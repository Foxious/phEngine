#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <vector>

typedef poolIndex unsigned int;

template <class T>
class ObjectPool
{
public:
	ObjectPool(unsigned int poolSize)
		: size(poolSize)
		, end (0)
		, nextFreeIndex(0)
	{
		data = new PoolItem[size];

		for (int i = 0; i < size; ++i)
		{
			data[i].alive = false;
			data[i].nextAvail = i+1;
		}
	}

	~ObjectPool()
	{
		delete [] data;
	}

	poolIndex Insert(T& object)
	{
		if (nextFreeIndex == size)
		{
			return (poolIndex)-1;
		}

		poolIndex returnVal = nextFreeIndex;
		PoolItem& freeSlot = data[nextFreeIndex];
		nextFreeIndex = freeSlot.nextAvail;
		freeSlot.data = object;
		freeSlot.alive = true;

		return returnVal;
	}
	void Remove(poolIndex index)
	{
		PoolItem& deadItem = data[index];
		deadItem.alive = false;
		deadItem.nextAvail = nextFreeIndex;
		nextFreeIndex = index;
	}

	T& operator[] (unsigned int index)
	{
		PoolItem* item = data[index]
		
		while(item->alive != true)
		{
			item = data[++index];
		}
	
		return item.data;

		// pH - this is a problem so far.
		// there is no test to make sure
		// the index is in range.
	}

private:
	template <class t>
	struct PoolItem
	{
		poolIndex nextAvail;
		bool alive;
		T data;
	};

private:
	const unsigned int size;
	unsigned int end;
	poolIndex nextFreeIndex;
	PoolItem<T>* data;
};

#endif