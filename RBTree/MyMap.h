

#pragma once

template<class K, class V>
class MyMap{
public:
	struct MapKeyOfValue{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};

	bool Insert(const pair<K, V>& kv){
		return _t.Insert(kv);
	}
private:
	RBTree<K, pair<K, V>, MapKeyOfValue> _t;
};

void TestMyMap(){
	MyMap<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(3, 2));
}
