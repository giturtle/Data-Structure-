
#pragma once
#include "RBTree.h"

template<class K>
class Set{
public:
	struct SetKeyOfValue{
		const K& operator()(const K& k)
		{
			return k;
		}
	};

	bool Insert(const K& k){
		return _t.Insert(k);
	}
private:
	RBTree<K, K, SetKeyOfValue> _t;
};

void TestMySet(){
	Set<int> s;
	s.Insert(3);
	s.Insert(1);
	s.Insert(4);

	
	Set<int>::Iterator it = s.Begin();
	while (it != s.End()){
		cout << *it << " ";
		++it;
	}
}
