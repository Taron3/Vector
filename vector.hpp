
#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class vector
{
public:
	vector(); // default ctor
	vector(const int size, const T &item = T()); // param ctor
	vector(const vector<T> &src); // copy ctor
	vector(vector<T> &&src); // move ctor
	
	~vector();

	vector<T>& operator=(const vector<T> &src);
	vector<T>& operator=(vector<T> &&src);
	
	void push(const T &item);
	void pop();
	T& front();
	T& back();
	bool empty() const;
	int size() const;
	int capacity() const;
	T& operator[](const int index);	

private:
	int m_capacity;
	int m_size;
	T *m_vector;

	void m_resize(const int newCapacity);
};

#endif // VECTOR_HPP
