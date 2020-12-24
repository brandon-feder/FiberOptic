class Edge
{
    public:
        float dist;
        short u;
        short v;

        Edge(short Iu, short Iv, float d)
        {
            u = Iu;
            v = Iv;

            dist = d;
        }

};

// Class that uses an adjacency list to represent the cities and their cables
class MST
{
    public:
        std::vector<Edge> forest;

        long sum = 0; // Sums of distances

        MST(std::vector<Cord> V)
        {
            // Push all edges between pairs of nodes
            for(int i = 0; i < V.size(); ++i)
            {
                for(int j = i+1; j < V.size(); ++j)
                    edges.push_back(Edge(
                        i, j,
                        V[i].dist(V[j])
                    ));
                isInForest.push_back(false);
            }

            isInForest[0] = true;
            
            // Comparison function
            auto sortRuleLambda = [] (Edge const& E1, Edge const& E2) -> bool
            {
                return E1.dist < E2.dist;
            };
            
            // Sort by length
            std::sort(edges.begin(), edges.end(), sortRuleLambda);

            for(short i = 0; i < V.size()-1; ++i)
            {
                getNextEdge();
                sum += forest[forest.size()-1].dist;
            }
        }

    private:
        std::vector<Edge> edges; // The adjacency list
        std::vector<bool> isInForest;

        void getNextEdge()
        {
            std::cout << "===================" << std::endl;
            for(std::vector<Edge>::iterator e = edges.begin(); e != edges.end(); e += 1)
            {
                if(isInForest[e->u] != isInForest[e->v])
                {
                    if(isInForest[e->u])
                        isInForest[e->v] = true;
                    else
                        isInForest[e->u] = true;
                    
                    forest.push_back(*e);

                    edges.erase(e);
                    break;
                }
            }
        }
};