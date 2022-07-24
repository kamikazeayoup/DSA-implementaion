#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#define ll long long
#define vi vector<int>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using  Set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

//implementation of vector (( refrenced by geekforgeeks ))
template<typename t>class vectorClass{

    // t is the pointer that will use it in our vector, it store address of the vector
    t* arr;
    //current is the size of the vector currently, capacity is the capacity of the vecotr
    int current;
    int capacity;

public:
    //to start use the vector, we should initialize it, by allocating storage and initial caapacity 1
    //for example : if we have capacity less than 0 , without initialize it by 1 , we can't double it, you will understand more in push function
    vectorClass(){
        arr = new t[1];
        capacity=1;
        current=0;
    }
    //deallocate memory storage when i needn't it, it prevent memory leak.
    //memory leak reduces the preformance of memory.
    ~vectorClass(){
        delete []arr;
    }

    //to push data in the vector, this way depends on the capacity, if the capacity equal the current,we should to do some operations
    void push(t data){
        if (current == capacity){
            //we will create a pointer contains array of double size of the last capacity to carry new data , then delete arr and reinitialize it by new values (temp values)
            t* temp = new t[2 * capacity];
            for (int i = 0 ; i < capacity ; i++)
                temp[i]=arr[i];

            delete [] arr;
            capacity*=2;
            arr = temp;
            //after redefind, delete the untemporary temp
            //delete [] temp;
        }
        //initialize the value of current index by adding the data,then increase current by one
        arr[current] = data;
        current++;
    }
    //here we push by index
    void push(t data , int index){
        //if index equal curent ,we will push regulary
        //otherwise we will reinitialize the value of index in arr by adding data on it
        if (index == current)
            push(data);
        else
            arr[index]=data;
    }
    //get the value of index, checking if index in boundry of arr , if out it will return -1
    t get(int index){
        if (current > index)
            return arr[index];
        else return -1;
    }
    //return capacity of the arr
    int getCapacity(){
        return capacity;
    }
    //return size of the arr
    int size(){
        return current;
    }
    //delete the last added by decrease current, it give a chance to redeclerated.
    void pop(){
        current--;
    }
    //print values in arr
    void print(){
        for (int i = 0 ; i < current ; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void clear(){
        //to prevent memory leak
       delete []arr;
       //re-initialize arr
       arr = new t[1];
       capacity = 1;
       current=0;
    }

};
int main() {
    vectorClass<int>vec;
    vec.push(5);
    vec.push(6);
    vec.push(7);
    vec.push(8);
    vec.push(9);
    vec.push(10);
    vec.push(11);
    vec.push(12);
    cout << "the values are : ";
    vec.print();
    cout << "the size = ";
    cout << vec.size() << endl;
    vec.pop();
    cout << "the size after pop = ";
    cout << vec.size() << endl;
    cout << "the values are: ";
    vec.print();
    cout << "get index in boundry (1) = ";
    cout << vec.get(1) << endl;
    cout << "get index out of boundry (100) = ";
    cout << vec.get(100) << endl;

    vec.clear();
    cout << "the size after clear = ";
    cout << vec.size() << endl;
    vec.push(10);
    vec.push(20);
    vec.push(30);
    vec.push(40);
    cout << "the values are : ";
    vec.print();
    cout << "the size = ";
    cout << vec.size() << endl;
}

/*time complexity :
 * - push : O(1)
 * - pop : O(1)
 * - print : O(N) n = size of arr
 * - get : O(1)
 * size : O(1)
 * clear : O(1)
 * push,push by index : O(1);
 */
