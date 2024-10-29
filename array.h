#pragma once

class array
{
private:
	int size;
	int* arr;

public:

	array(int n); 

	array(); 

	array(int* b, int n); 

	array(const array& other); 
	
	~array();

	void set(int size);

	array& operator =(const array& other);

	int getsize(); 

	void print(); 
	void scan(int size);

	int find(int key); 

	array& operator+=(int key); 

	array& operator+=(const array& other);

	bool operator!=(const array& other);

	bool operator==(const array& other);

	int max();

	int min();

	void sorting();

	int& operator[](int index);

	array& operator+(int key);

	array& operator+(const array& other);

	array& operator-=(int key);

	array& operator-(int key);

	friend std::ostream& operator<<(std::ostream& r, const array& other);
	friend std::istream& operator>>(std::istream& r, array& other);
};

