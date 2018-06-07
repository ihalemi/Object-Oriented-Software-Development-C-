// Ilias Halemi
// 062111133
// June 3rd 2018

#ifndef KVLIST_H
#define KVLIST_H

/**********************************************************************/
// class template KVList that manages lists of key-value pairs
// template will generate classes that contain two parallel arrays of N
// a key array of type K
// and a value array of type V
/**********************************************************************/

template <typename K, typename V, int N>
class KVList {
	K m_key[N];
	V m_value[N];
	int m_size;																		// number of entries in the key-value list

public:
	KVList() { m_size = 0; }														// creates an object in empty state
	size_t size() const { return m_size; }											// returns number of entries in key-value list
	const K& key(int i) const { return (i <= m_size) ? m_key[i] : m_key[0]; }		// returns a reference to the first element or 'i' element
	const V& value(int i) const { return (i <= m_size) ? m_value[i] : m_value[0]; }	// returns a reference to the first elemment or 'i' element 

	KVList& add(const K& k, const V& v)
	{
		if (m_size < N) { 
			m_key[m_size] = k;
			m_value[m_size] = v;
			m_size++;
		}
		return *this;
	}

	int find(const K& k) const {
		int index = 0;			// defaults to zero

		for (int i = 0; i < m_size; i++) {

			if (m_key[i] == k) { // if indexes match
				index = i;
			}
		}
		return index;
	}

	KVList& replace(int i, const K& k, const V& v) {
		if (i > 0 && i < m_size) {
			m_key[i] = k;
			m_value[i] = v;
		}
		return *this; 
	}
}; // end of class KVList

#endif // !KVLIST_H


