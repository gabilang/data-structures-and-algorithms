#include<vector>
#include<iostream>

using namespace std;

class ProtoVanEmdeBoasTree {
    public:
        int u;
        ProtoVanEmdeBoasTree *summary;
        vector<ProtoVanEmdeBoasTree *> cluster;
        int min;
        int max;
        ProtoVanEmdeBoasTree(int u);

        int high(int x) {
            return x / this->cluster.size();
        };

        int low(int x) {
            return x % this->cluster.size();
        };

        int index(int x, int y) {
            return x * this->cluster.size() + y;
        };

        void insert(int x) {
            if (this->min == -1) {
                this->empty_insert(x);
            } else {
                if (x < this->min) {
                    swap(x, this->min);
                }
                if (this->u > 2) {
                    if (this->cluster[this->high(x)]->min == -1) {
                        this->summary->insert(this->high(x));
                        this->cluster[this->high(x)]->empty_insert(this->low(x));
                    } else {
                        this->cluster[this->high(x)]->insert(this->low(x));
                    }
                }
                if (x > this->max) {
                    this->max = x;
                }
            }
        };

        void empty_insert(int x) {
            this->min = x;
            this->max = x;
        };

        int get_min() {
            return this->min;
        };

        int get_max() {
            return this->max;
        };

        bool is_empty() {
            return this->min == -1;
        };

        int get_u() {
            return this->u;
        };

        ProtoVanEmdeBoasTree *get_summary() {
            return this->summary;
        };

        vector<ProtoVanEmdeBoasTree *> get_cluster() {
            return this->cluster;
        };
};

ProtoVanEmdeBoasTree::ProtoVanEmdeBoasTree(int u) {
    this->u = u;
    this->min = -1;
    this->max = -1;
    if (u <= 2) {
        this->summary = NULL;
        this->cluster = vector<ProtoVanEmdeBoasTree *>(0);
    } else {
        int upper_sqrt = 1;
        while (upper_sqrt * upper_sqrt < u) {
            upper_sqrt++;
        }
        this->summary = new ProtoVanEmdeBoasTree(upper_sqrt);
        this->cluster = vector<ProtoVanEmdeBoasTree *>(upper_sqrt);
        for (int i = 0; i < upper_sqrt; i++) {
            this->cluster[i] = new ProtoVanEmdeBoasTree(upper_sqrt);
        }
    }
}

bool is_member(ProtoVanEmdeBoasTree *v, int x) {
    if (x == v->get_min() || x == v->get_max()) {
        return true;
    } else if (v->get_u() == 2) {
        return false;
    } else {
        return is_member(v->get_cluster()[v->high(x)], v->low(x));
    }
}

void insert(ProtoVanEmdeBoasTree *v, int x) {
    if (v->get_min() == -1) {
        v->insert(x);
    } else {
        if (x < v->get_min()) {
            int temp = x;
            x = v->get_min();
            v->insert(temp);
        }
        if (v->get_u() > 2) {
            if (v->get_cluster()[v->high(x)]->get_min() == -1) {
                insert(v->get_summary(), v->high(x));
                v->get_cluster()[v->high(x)]->insert(v->low(x));
            } else {
                insert(v->get_cluster()[v->high(x)], v->low(x));
            }
        }
        if (x > v->get_max()) {
            v->max = x;
        }
    }
}

void delete_member(ProtoVanEmdeBoasTree *v, int x) {
    if (v->get_min() == v->get_max()) {
        v->min = -1;
        v->max = -1;
    } else if (v->get_u() == 2) {
        if (x == 0) {
            v->min = 1;
        } else {
            v->min = 0;
        }
        v->max = v->min;
    } else {
        if (x == v->get_min()) {
            int first_cluster = v->get_summary()->get_min();
            x = v->index(first_cluster, v->get_cluster()[first_cluster]->get_min());
            v->min = x;
        }
        delete_member(v->get_cluster()[v->high(x)], v->low(x));
        if (v->get_cluster()[v->high(x)]->get_min() == -1) {
            delete_member(v->get_summary(), v->high(x));
            if (x == v->get_max()) {
                int summary_max = v->get_summary()->get_max();
                if (summary_max == -1) {
                    v->max = v->min;
                } else {
                    v->max = v->index(summary_max, v->get_cluster()[summary_max]->get_max());
                }
            }
        } else if (x == v->get_max()) {
            v->max = v->index(v->high(x), v->get_cluster()[v->high(x)]->get_max());
        }
    }
}

int successor(ProtoVanEmdeBoasTree *v, int x) {
    if (v->get_u() == 2) {
        if (x == 0 && v->get_max() == 1) {
            return 1;
        } else {
            return -1;
        }
    } else if (v->get_min() != -1 && x < v->get_min()) {
        return v->get_min();
    } else {
        int max_low = v->get_cluster()[v->high(x)]->get_max();
        if (max_low != -1 && v->low(x) < max_low) {
            int offset = successor(v->get_cluster()[v->high(x)], v->low(x));
            return v->index(v->high(x), offset);
        } else {
            int succ_cluster = successor(v->get_summary(), v->high(x));
            if (succ_cluster == -1) {
                return -1;
            } else {
                int offset = v->get_cluster()[succ_cluster]->get_min();
                return v->index(succ_cluster, offset);
            }
        }
    }
}

int predecessor(ProtoVanEmdeBoasTree *v, int x) {
    if (v->get_u() == 2) {
        if (x == 1 && v->get_min() == 0) {
            return 0;
        } else {
            return -1;
        }
    } else if (v->get_max() != -1 && x > v->get_max()) {
        return v->get_max();
    } else {
        int min_low = v->get_cluster()[v->high(x)]->get_min();
        if (min_low != -1 && v->low(x) > min_low) {
            int offset = predecessor(v->get_cluster()[v->high(x)], v->low(x));
            return v->index(v->high(x), offset);
        } else {
            int pred_cluster = predecessor(v->get_summary(), v->high(x));
            if (pred_cluster == -1) {
                if (v->get_min() != -1 && x > v->get_min()) {
                    return v->get_min();
                } else {
                    return -1;
                }
            } else {
                int offset = v->get_cluster()[pred_cluster]->get_max();
                return v->index(pred_cluster, offset);
            }
        }
    }
}

int main() {
    ProtoVanEmdeBoasTree *v = new ProtoVanEmdeBoasTree(16);
    v->insert(15);
    v->insert(2);
    v->insert(3);
    v->insert(4);
    v->insert(6);
    v->insert(5);
    v->insert(7);
    v->insert(14);
    v->insert(9);


    cout << "min: " << v->get_min() << endl;
    cout << "max: " << v->get_max() << endl;
    cout << "successor of 5: " << successor(v, 5) << endl;
    cout << "predecessor of 5: " << predecessor(v, 5) << endl;
    delete_member(v, 5);
    cout << successor(v, 5) << endl;
    cout << predecessor(v, 5) << endl;
    return 0;
}
