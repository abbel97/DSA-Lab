// Evaluate Decision leetcode 399

//We are given equation like a/b = k, we answer queries using for other 
//          division using graph-based ratio.

class Solution {
    public:
        void DFS(string place, string destination,unordered_map<string, vector<pair<string, double>>>& graph,
                 double& answer, double placeProduct, unordered_set<string>& visited) {
            if (visited.find(place) != visited.end()) {
                return;
            }
            visited.insert(place);
            if (place == destination) {
                answer = placeProduct;
                return;
            }
            for (auto nextdoor : graph[place]) {
                string nextNode = nextdoor.first;
                double val = nextdoor.second;
                DFS(nextNode, destination, graph, answer, placeProduct * val, visited);
            }
        }W
    
        vector<double> calcEquation(vector<vector<string>>& equations,vector<double>& values,vector<vector<string>>& queries) {
            unordered_map<string, vector<pair<string, double>>> graph;
    
            for (int i = 0; i < equations.size(); i++) {
                string nodeA = equations[i][0];
                string nodeB = equations[i][1];
                double val = values[i];
    
                graph[nodeA].push_back({nodeB, val});
                graph[nodeB].push_back({nodeA, 1.0 / val});
            }
             vector<double> result;
    
            for (int i = 0; i < queries.size(); i++) {
                string start = queries[i][0];
                string end = queries[i][1];
    
                double answer = -1.0;
                double product = 1;
    
                if (graph.find(start) != graph.end()) {
                    unordered_set<string> visited;
                    DFS(start, end, graph, answer, product, visited);
                }
                result.push_back(answer);
            }
            return result;
        }
    };