#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Marti_02


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
  const vector<Dir> directions_w = {Up,Down,Left,Right};
  const vector<Dir> directions = {Down, DR, Right, RU, Up, UL, Left, LD};



/// VOLDEMORT TRATAMIENTO ///
  //Zona de paligro VOLDEMORT 
  set<Pos> calculate_danger_cells() {
    set<Pos> danger;              // set de zona r1 peleigrosa
    for(Dir d : directions) {
      Pos adj = pos_voldemort() + d;
      if (pos_ok(adj)) {
        danger.insert(adj);
      }
    }
    return danger;
  }

  // MOvimiento seguro??
  Dir safe_move(int id, const set<Pos>& danger_zone) {
    Pos current_pos = unit(id).pos;

    for (Dir d : directions_w) {
        Pos next_pos = current_pos + d;
        if (pos_ok(next_pos) && !danger_zone.count(next_pos) && cell(next_pos).type == Corridor) {
            return d; // Devuelve la primera dirección segura encontrada
        }
    }

    return Down; // Si no hay movimientos seguros, toma uno predeterminado
  }


///FUNCIONES DE AYUDA ///
  // Convierte (i, j) en un índice lineal
  int index(int i, int j) {
    return i * board_cols() + j; 
  }

  //Devuelve la direccion a la cula se tienen que mover para llegar a dicha posicion
  Dir convert_pos_to_dir(const Pos& current, const Pos& next, char type) {
    if (type == 'w') {
      for (Dir d : directions_w) {
        if (current + d == next) return d;
      }
    }
    else {
      for (Dir d : directions) {
        if (current + d == next) return d;
      }
    }
    return Down;
  }


/// BFS PARA ENCONTRAR  QUE HAY ///
  // revisar idea si eso
  Pos find_closest_target(const Pos& start, const set<Pos>& danger_zone) {
    queue<Pos> q;            // Cola para BFS
    set<Pos> visited;        // Celdas ya visitadas
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
      Pos current = q.front();
      q.pop();

      // Comprobar si la celda actual cumple el criterio de búsqueda
      
      if (cell(current).book) return current; // Si es un libro, devolver la posición
    
      int current_unit_id = cell(current).id; // ID de la unidad en la celda actual
      if (current_unit_id != -1) {
        Unit enemy = unit(current_unit_id);
        if (enemy.player != me() && enemy.type == Wizard) { // Es un mago enemigo
          int my_strength = magic_strength(me());
          int enemy_strength = magic_strength(enemy.player);
          if (enemy_strength < 2 * my_strength) {
            return current; // Si el enemigo cumple, devolver la posición
          }
        }
      }
      

      // Explorar vecinos
      for (Dir d : directions_w) {
        Pos neighbor = current + d;
        if (pos_ok(neighbor) && !visited.count(neighbor) && !danger_zone.count(neighbor) && cell(neighbor).type == Corridor) {
          q.push(neighbor);
          visited.insert(neighbor);
        }
      }
    }

    return {-1, -1}; // Si no se encuentra objetivo, devolver posición inválida
}



///ALGORISMO A* PARA MAGOS///

  // CLaculo heuristica
  int heuristic(const Pos& p, const Pos& target) {
    return abs(p.i - target.i) + abs(p.j - target.j);
  }

  //implementacion de A*
  Pos a_star_first_step(const Pos& start, const Pos& target, const set<Pos>& danger_zone) {
    int rows = board_rows();
    int cols = board_cols();
    int total_cells = rows * cols;

    vector<int> g_cost(total_cells, INT_MAX); // Costos acumulados
    vector<Pos> came_from(total_cells, {-1, -1}); // Predecesores
    priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, greater<>> untracked; // Cola de prioridad

    g_cost[index(start.i, start.j)] = 0;
    untracked.push({0, start}); // Iniciar con la posición de start

    while (!untracked.empty()) {
      Pos current = untracked.top().second;
      untracked.pop();

      // Si llegamos al objetivo, reconstruimos el camino
      if (current == target) {
        vector<Pos> path;
        while (current != start) {
          path.push_back(current);
          current = came_from[index(current.i, current.j)];
        }
        reverse(path.begin(), path.end());  // Invertimos para obtener desde start
        return path[0];  // Retornamos la primera posición en el camino
      }

      // Explorar vecinos
      for (Dir d : directions_w) {
        Pos neighbor = current + d;
        int neighbor_index = index(neighbor.i, neighbor.j);

        // Verificar condiciones
        if (pos_ok(neighbor) && !danger_zone.count(neighbor) && cell(neighbor).type == Corridor) {
          int tentative_g_cost = g_cost[index(current.i, current.j)] + 1; // Coste del camino hasta el vecino
          if (tentative_g_cost < g_cost[neighbor_index]) {
            g_cost[neighbor_index] = tentative_g_cost;
            int f_cost = tentative_g_cost + heuristic(neighbor, target); // Cálculo del f-cost (g + h)
            untracked.push({f_cost, neighbor}); // Añadir a la cola de prioridad
            came_from[neighbor_index] = current; // Guardar el predecesor
          }
        }
      }
    }

  return {-1, -1}; // Si no hay camino, devolver una posición inválida
}



  
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    // 1. Calcular las celdas peligrosas alrededor de Voldemort
    set<Pos> danger_zone = calculate_danger_cells();
    
    // 2. DIvidir magos

    for (int id : wizards(me())) {
      Pos current_pos = unit(id).pos;
      Pos target;
      //Exploradors o luchadores depende de proximidad
      
      target =find_closest_target(current_pos, danger_zone); // enemigo fuerza <2*mifuerza o libro mas cercano
      

      // calcul ruta
      if (target != Pos(-1, -1)) { 
        Pos next = a_star_first_step(current_pos, target, danger_zone);
        if (next != Pos(-1,-1)) {
          move(id, convert_pos_to_dir(current_pos, next, 'w'));
        }
      }

      // Si no hay objetivo, moverse seguro
      else move(id, safe_move(id, danger_zone));
    }

    // Mover el fantasma de manera segura
    int ghost_id = ghost(me());
    Dir ghost_move = safe_move(ghost_id, danger_zone);
    move(ghost_id, ghost_move);


  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
