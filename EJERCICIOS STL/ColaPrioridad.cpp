#include <iostream>
#include <queue>
#include <string>
#include <vector>

// Definimos un tipo Task que agrupa la prioridad y la descripción
struct Task {
    int priority;
    std::string description;

    // Constructor
    Task(int p, const std::string& desc)
      : priority(p), description(desc) {}
};

// Comparator para que la priority_queue saque primero el Task con menor `priority`
struct TaskCompare {
    bool operator()(Task const& a, Task const& b) const {
        // true si 'a' tiene MENOS prioridad que 'b' (para que b salga antes)
        return a.priority > b.priority;
    }
};

int main() {
    // Creamos la cola de prioridad con nuestro comparador
    std::priority_queue<Task, std::vector<Task>, TaskCompare> pq;

    // a) Insertamos las tareas dadas
    pq.emplace(3, "Revisión de informes");
    pq.emplace(1, "Preparar presentación");
    pq.emplace(4, "Responder correos urgentes");
    pq.emplace(2, "Reunión con el equipo");
    pq.emplace(5, "Planificar nueva estrategia");

    std::cout << "Procesando tareas por orden de prioridad:\n\n";

    // Mientras haya tareas, las extraemos de más urgente a menos urgente
    while (!pq.empty()) {
        Task t = pq.top();
        pq.pop();
        std::cout
            << "Prioridad " << t.priority
            << " → " << t.description
            << "\n";
    }

    return 0;
}
