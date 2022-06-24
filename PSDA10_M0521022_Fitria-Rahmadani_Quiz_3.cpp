#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <stack>

enum node {
    SURABAYA,
    SIDOARJO,
    MADIUN,
    KEDIRI,
    MALANG,
    JEMBER,
    BANYUWANGI,

    J_KOTA,
    NODE_INVALID = -1
};

std::map<node, std::string> node_name;

double graph[J_KOTA][J_KOTA];

void add_edge(node asal, node tujuan, double jarak) {
    graph[asal][tujuan] = jarak;
    graph[tujuan][asal] = jarak;
}

int main() {
    node_name[SURABAYA] = "Surabaya";
    node_name[SIDOARJO] = "Sidoarjo";
    node_name[MADIUN] = "Madiun";
    node_name[KEDIRI] = "Kediri";
    node_name[MALANG] = "Malang";
    node_name[JEMBER] = "Jember";
    node_name[BANYUWANGI] = "Banyuwangi";

    for (int i = 0; i < J_KOTA; i++) {
        for (int j = 0; j < J_KOTA; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            } else {
                graph[i][j] = -1.0;
            }
        }
    }

    add_edge(SURABAYA, SIDOARJO, 25.8);
    add_edge(SURABAYA, MADIUN, 165);
    add_edge(SIDOARJO, MADIUN, 164);
    add_edge(SIDOARJO, MALANG, 71.3);
    add_edge(SIDOARJO, JEMBER, 178);
    add_edge(SIDOARJO, BANYUWANGI, 283);
    add_edge(MADIUN, KEDIRI, 93.4);
    add_edge(KEDIRI, MALANG, 103);
    add_edge(MALANG, JEMBER, 155);
    add_edge(JEMBER, BANYUWANGI, 109);

    std::set<node> visited, unvisited;
    for (int i = 0; i < J_KOTA; i++) {
        unvisited.insert((node)i);
    }

    std::map<node, double> path_distance;
    for (int i = 0; i < J_KOTA; i++) {
        path_distance[(node)i] = INFINITY;
    }

    std::map<node, node> path_parent;
    for (int i = 0; i < J_KOTA; i++) {
        path_parent[(node)i] = NODE_INVALID;
    }

    node node_asal = MADIUN;
    node node_tujuan = BANYUWANGI;

    path_distance[node_asal] = 0.0;

    while (!unvisited.empty()) {
        node pick = NODE_INVALID;
        for (
            std::set<node>::iterator it = unvisited.begin();
            it != unvisited.end();
            ++it
        ) {
            if (pick == NODE_INVALID) {
                pick = *it;
            } else {
                if (path_distance[*it] < path_distance[pick]) {
                    pick = *it;
                }
            }
        }

        visited.insert(pick);
        unvisited.erase(pick);

        if (visited.count(node_tujuan) == 1) {
            break;
        }

        for (int i = 0; i < J_KOTA; i++) {
            if ((graph[pick][i] > 0.0) && (unvisited.count((node)i) == 1)) {
                double distance_old = path_distance[(node)i];
                double distance_new = path_distance[pick] + graph[pick][i];
                if (distance_new < distance_old) {
                    path_distance[(node)i] = distance_new;
                    path_parent[(node)i] = pick;
                }
            }
        }
    }

    double path_shortest_distance = 0.0;
    std::stack<node> path_stack;
    for (node path = node_tujuan; path != NODE_INVALID; path = path_parent[path]) {
        path_stack.push(path);
    }

    std::cout << "Rute dari " << node_name[node_asal] << " ke " << node_name[node_tujuan] << " : " << std::endl;

    while (!path_stack.empty()) {
        node path = path_stack.top();
        path_stack.pop();

        double jarak = 0.0;
        if (path != node_asal) {
            jarak = graph[path][path_parent[path]];
            path_shortest_distance = path_shortest_distance + jarak;
        }

        std::cout << " -----> " << node_name[path] << " dengan jarak " << jarak << " km" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Total rute terpendek yang dapat ditempuh dari " << node_name[node_asal] << " ke " << node_name[node_tujuan] << " : " << path_shortest_distance << " km" << std::endl;

    return 0;
}