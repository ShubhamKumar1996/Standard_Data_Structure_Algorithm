class Comp {
public:
	bool operator()(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
		if(a.first == b.first) {
			if(a.second.first == b.second.first) {
				return a.second.second <= b.second.second;
			}
			return a.second.first < b.second.first;
		}
		return a.first > b.first;
	}
};