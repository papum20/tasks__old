//COPIATA


#include <vector>
#include <iostream>
#include <limits>
#include <queue>

const unsigned INFINITO = std::numeric_limits<unsigned>::max();
typedef unsigned vertice_t;

struct arco_t {
    vertice_t coda, testa; // I due estremi collegati
    unsigned peso; // Il peso dell'arco
};

std::vector<arco_t> archi; // Lista degli archi
std::vector<std::vector<arco_t>> vicini; // Liste di adiacenza
unsigned N, M;

struct info_t {
    vertice_t ultimo; // Il nodo finale del cammino
    unsigned peso; // Il peso (cumulativo) del cammino

    bool operator< (const info_t& o) const {
    return peso > o.peso;
    }
};



    unsigned risposta = INFINITO;

unsigned percorso_minimo(vertice_t partenza, vertice_t arrivo) {
    std::vector<unsigned> distanza(N, INFINITO);
    std::priority_queue<info_t> coda;
    coda.push({partenza, 0});

    while (!coda.empty()) {

        vertice_t u = coda.top().ultimo;
        unsigned w = coda.top().peso;
        coda.pop();

        if (distanza[u] == INFINITO) {

            distanza[u] = w;

            for (const arco_t& arco: vicini[u]) {
                if ((arco.coda == partenza && arco.testa == arrivo) || w+arco.peso>std::min(risposta,distanza[arrivo])) {
                   continue;
                }
                coda.push({arco.testa, w + arco.peso});
            }
        }
    }

    return distanza[arrivo];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin >> N >> M;
    vicini.resize(N);

    for (int i = 0; i < M; ++i) {
        vertice_t u, v;
        unsigned w;
        std::cin >> u >> v >> w;

        --u;
        --v;

        vicini[u].push_back({u, v, w}); // arco u -> v di peso w
        vicini[v].push_back({v, u, w}); // arco u <- v di peso w

        archi.push_back({u, v, w});
    }


    for (const arco_t& arco: archi) {

        unsigned pm = percorso_minimo(arco.coda, arco.testa);

        if (pm != INFINITO)
           risposta = std::min(risposta, arco.peso + pm);
    }

    std::cout << risposta << std::endl;
}











//ARCHI





#include <iostream>
#include <bits/stdc++.h>
#include <limits>
using namespace std;





unsigned INFINITO = numeric_limits<unsigned>::max();
typedef unsigned vertice;

unsigned N, M;
struct arco{
	vertice coda, testa;
	unsigned peso;
};
struct info{
	vertice ultimo;
	unsigned peso;
	bool operator< (const info& a) const{
		return a.peso < peso;
	}
};
vector <vector<arco>> vicini;
vector <arco> archi;






unsigned percorso_minimo(vertice partenza, vertice arrivo)
{
	vector <unsigned> distanza(N, INFINITO);
	priority_queue <info> coda;
	coda.push({partenza, 0});

	while(!coda.empty())
	{
		vertice u = coda.top().ultimo;
		unsigned w = coda.top().peso;
		coda.pop();

		if(distanza[u] == INFINITO){
			distanza[u] = w;

			for(auto arco:vicini[u]){
				if(arco.coda == partenza && arco.testa == arrivo) continue;
					coda.push({arco.testa, w+arco.peso});
			}
		}
	}

	return distanza[arrivo];
}








int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> N >> M;
	vicini.resize(N);

	for(int i = 0; i < M; i++){
		vertice u, v;
		unsigned w;
		cin >> u >> v >> w;
		u--;
		v--;
		vicini[u].push_back({u,v,w});
		vicini[v].push_back({v,u,w});
		archi.push_back({u,v,w});
	}



	unsigned risultato = INFINITO;

	for(auto arco:archi)
		risultato = min(risultato, percorso_minimo(arco.coda, arco.testa)+arco.peso);

	cout << risultato;

}
















//PUNTI






//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <limits>
//#include <queue>
//#include <set>
//using namespace std;
//
//
//
//
//
//unsigned INFINITO = numeric_limits<int>::max();
//int N, M, mn = INFINITO;
//struct road{
//	int t, l;	//to, length
//};
//unordered_map <int, vector<road> > roads;
////struct arco{
////	int f, t, l;	//from, to, length
////};
////unordered_map <int, vector<arco> > archi;
//auto comparator = [](const road&a, const road&b){
//	return a.l > b.l;
//};
//
//
//
//
//
//int Djikstra(int start, int end)
//{
////	cout << "START: " << start << " " << end << endl;
//
//	unordered_map <int, int> mnL;	//min length
//	for(int i = 0; i <= N; i++){
//		if(i != start) mnL[i] = INFINITO;
//	}
//	priority_queue <road, vector<road>, decltype(comparator)> visited(comparator);
//	for(auto i:roads[start]){
//		if(i.t != end) visited.push({i.t,i.l});
//	}
//
//
//	while(!visited.empty())
//	{
//		int T = visited.top().t, L = visited.top().l;
//		visited.pop();
////		cout << "POS: "<< T << " "<< L<<"; ";
//		if(mnL[T] != INFINITO) continue;
////		cout << "endl";
//		mnL[T] = L;
//
////		if(T != end){
//			for(auto i:roads[T]){
//				if(mnL[i.t] == INFINITO){
//					visited.push({i.t, L+i.l});
////				cout << i.t << " " << i.l<<endl;
//				}
//			}
////		}
//
//	}
//
//
//	return mnL[end];
//
//}
//
//
//
//
//
//
//
//
//
//int main()
//{
////	freopen("input.txt","r",stdin);
////	freopen("output.txt","w",stdout);
//
//
//	cin >> N >> M;
//
//	for(int i = 0; i < M; i++){
//		int a, b, l;
//		cin >> a >> b >> l;
//		roads[a].push_back({b,l});
//		roads[b].push_back({a,l});
//	}
//
//
//
//
//	set <int> started;
//
//	for(int s = 1; s <= N; s++){
//		started.insert(s);
//		for(auto e:roads[s]){
//			if(started.find(e.t) == started.end() )
//				mn = min(mn, Djikstra(s, e.t) + e.l);
//		}
//	}
//
//
//
//	cout << mn;
//
//
//}








/*

6 10
1 2 1
3 2 2
5 2 6
4 5 2
1 4 2
3 5 1
3 4 7
5 1 5
2 6 4
3 6 3

*/




















//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <limits>
//#include <queue>
//#include <set>
//using namespace std;
//
//
//
//
//
//int N, M, mn = numeric_limits<int>::max();
//struct road{
//	int t, l;	//to, length
////	bool operator> (const road &a){
////		return a.l < l;
////	};
//};
//unordered_map <int, vector<road> > roads;
//auto comparator = [](const road&a, const road&b){
//	return a.l > b.l;
//};
//
//
//
//
//
//
//unordered_map <int, int> mnL;	//min length
////set <int> used;
//
//void Djikstra(int pos, int len, int end)
//{
//	if(pos == end)
//		return;
//
//
//	priority_queue <road, vector<road>, decltype(comparator)> adjacent(comparator);
//	cout << endl;
//	for(auto i:roads[pos]){
//		int T = i.t, L = len + i.l;
//		if(mnL[T] == 0 || L < mnL[T]){
//			cout << T << len << i.l;
//			adjacent.push({T, L});
//			mnL[T] = L;
//			cout << mnL[T]<<endl;
//		}
//	}
//
//
////	used.insert(pos);
//	while(!adjacent.empty()){
//		int T = adjacent.top().t, L = adjacent.top().l;
//		cout << endl << "POS: " <<pos << ": " <<"T " << T<<": ";
//		if(mnL[T] == 0 || L <= mnL[T]){
//			cout << adjacent.top().l << "<" << mnL[T];
//			Djikstra(T, L, end);
//		}
//		adjacent.pop();
//	}
////	used.erase(pos);
//
//}
//
//
//
//
//
//
//
//
//
//
//int main()
//{
////	freopen("input.txt","r",stdin);
////	freopen("output.txt","w",stdout);
//
//
//	cin >> N >> M;
//
//	for(int i = 0; i < M; i++){
//		int a, b, l;
//		cin >> a >> b >> l;
//		roads[a].push_back({b,l});
//		roads[b].push_back({a,l});
//	}
//
//
//
//
//	set <int> started;
//
//	for(int s = 1; s <= N; s++){
//		started.insert(s);
//		for(int e = 0; e < roads[s].size(); e++){
//			if(started.find(roads[s][e].t) == started.end() ){
//				cout << "\n\nSTART "<<s<<" END"<<roads[s][e].t<<endl<<endl;
//				mnL.clear();
//				mnL[s] = 1;
//				road tmp = roads[s][e];
//				roads[s].erase(roads[s].begin()+e);
//				Djikstra(s, 0, tmp.t);
//				roads[s].insert(roads[s].begin()+e, tmp);
//				mn = min(mn, mnL[tmp.t]+tmp.l);
//			}
//		}
//	}
//
//
//	cout << "\n\n\n\n\n\n"<<mn;
//
//
//
//}
