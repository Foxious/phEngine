#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <vector>

typedef unsigned int poolIndex;
struct PoolItem;

template <class T>
class ObjectPool
{
public:
	ObjectPool(unsigned int poolSize)
		: size(poolSize)
		, nextFreeIndex(0)
		, count(0)
	{
		data = new PoolItem[size];

		for (unsigned int i = 0; i < size; ++i)
		{
			data[i].nextAvail = i+1;
		}
	}

	~ObjectPool()
	{
		delete [] data;
	}

	struct PoolItem
	{
		poolIndex nextAvail;
		T data;

		bool IsAlive() { return nextAvail == (poolIndex)-1; }
		void SetAlive() { nextAvail = (poolIndex)-1; }
	};

	class Iterator
	{
	public:
		Iterator( PoolItem* poolData, poolIndex start, poolIndex length)
			: pool(poolData)
			, index(start)
			, size(length)
		{
			if ( !poolData[start].IsAlive() )
			{
				Next();
			}
		}
		bool IsValid()
		{
			return index < size;
		}

		void Next()
		{
			++index;
			while( IsValid() && !pool[index].IsAlive() )
			{
				++index;
			}
		}

		T& GetValue()
		{
			return pool[index].data;
		}

		void operator++ ()
		{
			Next();
		}

		void operator++(int)
		{
			Next();
		}

		T& operator* ()
		{
			return GetValue();
		}

		T* operator->()
		{
			return &GetValue();
		}

	private:
		poolIndex index;
		PoolItem* pool;
		poolIndex size;

	};

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
		freeSlot.SetAlive();
		++count;

		return returnVal;
	}
	void Remove(poolIndex index)
	{
		PoolItem& deadItem = data[index];
		deadItem.nextAvail = nextFreeIndex;
		nextFreeIndex = index;
		--count;
	}

	Iterator Begin()
	{
		return Iterator(data, 0, size);
	}

	T& operator[] (unsigned int index)
	{
		PoolItem* item = &data[index];
		
		while( !item->IsAlive() )
		{
			item = &data[++index];
		}
	
		return item->data;

		// pH - this is a problem so far.
		// there is no test to make sure
		// the index is in range.
	}

private:

private:
	const unsigned int size;
	poolIndex nextFreeIndex;
	PoolItem* data;
	unsigned int count;
};

#endif