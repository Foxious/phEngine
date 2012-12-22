#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <assert.h>
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

	class PoolItemPtr
	{
	public:
		PoolItemPtr()
			: item(0)
			, index( (poolIndex)-1 )
		{
		}
		PoolItemPtr(PoolItem* poolItem, poolIndex itemIndex)
			: item(poolItem)
			, index(itemIndex)
		{
		}

		poolIndex Index() { return index; }

		T& operator*()
		{
			assert(item->IsAlive());
			return item->data;
		}

		const T& operator*() const
		{
			assert(item->IsAlive());
			return this->operator*();
		}

		T* operator->()
		{
			assert(item->IsAlive());
			return &item->data;
		}

		const T* operator->() const
		{
			assert(item->IsAlive());
			return &item->data;
		}


	private:
		PoolItem* item;
		poolIndex index;
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

		poolIndex GetIndex() const
		{
			return index;
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

	PoolItemPtr Insert(T& object)
	{
		if (nextFreeIndex == size)
		{
			// pH TODO - how do we handle this case?
			//return (poolIndex)-1;
		}

		poolIndex index = nextFreeIndex;
		PoolItem& freeSlot = data[index];
		nextFreeIndex = freeSlot.nextAvail;
		freeSlot.data = object;
		freeSlot.SetAlive();
		++count;

		PoolItemPtr returnVal(&freeSlot, index);

		return returnVal;
	}
	void Remove(poolIndex index)
	{
		PoolItem& deadItem = data[index];
		deadItem.nextAvail = nextFreeIndex;
		nextFreeIndex = index;
		--count;
	}

	void Remove(PoolItemPtr& poolItem)
	{
		Remove(poolItem.Index());
	}
	
	void Remove(const Iterator* iterator)
	{
		Remove(iterator->GetIndex());
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
	const unsigned int size;
	poolIndex nextFreeIndex;
	PoolItem* data;
	unsigned int count;
};

#endif