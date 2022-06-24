#include <iostream>
#include <list>
#include <map>

enum node {
    SURABAYA,
    SIDOARJO,
    MADIUN,
    KEDIRI,
    MALANG,
    JEMBER,
    BANYUWANGI,

    NODE_COUNT
};

node djs_find(const std::map<node, node> &loc, node elemen) {
    if (loc.at(elemen) == elemen) {
        return elemen;
    }
    return djs_find(loc, loc.at(elemen));
}

void djs_union(std::map<node, node> &loc, node a, node b) {
    node loc_a = djs_find(loc, a);
    node loc_b = djs_find(loc, b);
    loc[loc_a] = loc_b;
}

struct edge {
    node node_asal;
    node node_tujuan;
    double jarak;

    edge(node _node_asal, node _node_tujuan, double _jarak) {
        node_asal = _node_asal;
        node_tujuan = _node_tujuan;
        jarak = _jarak;
    }
};

bool is_tree(const std::list<edge> &graph) {
    // Disjoint set
    std::map<node, node> djs;
    for (int i = 0; i < NODE_COUNT; i++) {
        djs[(node)i] = (node)i;
    }

    for (
        std::list<edge>::const_iterator it = graph.begin();
        it != graph.end();
        ++it
    ) {
        node loc_asal = djs_find(djs, it->node_asal);
        node loc_tujuan = djs_find(djs, it->node_tujuan);

        if (loc_asal == loc_tujuan) {
            return false;
        }

        djs_union(djs, loc_asal, loc_tujuan);
    }
    return true;
}

std::list<edge> sort_edges(std::list<edge> graph) {
    std::list<edge> sorted;
    while (!graph.empty()) {
        std::list<edge>::iterator select = graph.begin();
        for (
            std::list<edge>::iterator it = graph.begin();
            it != graph.end();
            ++it
        ) {
            if (it->jarak < select->jarak) {
                select = it;
            }
        }
        sorted.push_back(*select);
        graph.erase(select);
    }
    return sorted;
}

int main() {
    std::list<edge> graph;
    graph.push_back(edge(SURABAYA, SIDOARJO, 25.8));
    graph.push_back(edge(SURABAYA, MADIUN, 165));
    graph.push_back(edge(SIDOARJO, MADIUN, 164));
    graph.push_back(edge(SIDOARJO, MALANG, 71.3));
    graph.push_back(edge(SIDOARJO, JEMBER, 178));
    graph.push_back(edge(SIDOARJO, BANYUWANGI, 283));
    graph.push_back(edge(MADIUN, KEDIRI, 93.4));
    graph.push_back(edge(KEDIRI, MALANG, 103));
    graph.push_back(edge(MALANG, JEMBER, 155));
    graph.push_back(edge(JEMBER, BANYUWANGI, 109));

    graph = sort_edges(graph);

    // minimum spanning tree
    std::list<edge> mst;
    while (mst.size() < (NODE_COUNT - 1)) {
        edge pick = graph.front();
        graph.pop_front();

        mst.push_back(pick);
        if (!is_tree(mst)) {
            mst.pop_back();
        }
    }

    double mst_jarak = 0.0;
    for (
        std::list<edge>::iterator it = mst.begin();
        it != mst.end();
        ++it
    ) {
        std::cout << "Jarak rute yang dipilih : " << it->jarak << " km" << std::endl;
        mst_jarak = mst_jarak + it->jarak;
    }
    std::cout << std::endl;
    std::cout << "Total rute terpendek untuk mengunjungi seluruh kota : " << mst_jarak << " km" << std::endl;

    return 0;
}