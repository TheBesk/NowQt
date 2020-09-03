#ifndef DEEPPOINTER_H
#define DEEPPOINTER_H

template <class T>
class deepPointer{
private:
    T* ptr;
public:
    deepPointer(T* =nullptr);
    deepPointer(const deepPointer&);
    deepPointer& operator=(const deepPointer&);
    T* operator->() const;
    ~deepPointer();
    bool operator==(const deepPointer&) const;
    bool operator!=(const deepPointer&) const;
    bool operator>(const deepPointer&) const;
    bool operator<(const deepPointer&) const;
    operator T*() const;
};

template <class T>
deepPointer<T>::deepPointer(T* itm): ptr(itm){}

template <class T>
deepPointer<T>::deepPointer(const deepPointer& dptr){
      if(!dptr)
          ptr=nullptr;
      else
          ptr=dptr.ptr->clone();
}

template <class T>
deepPointer<T>& deepPointer<T>::operator=(const deepPointer& dptr){
        if(this != &dptr){
            if(ptr)
                delete ptr;
            ptr = dptr.ptr->clone();
    }
    return *this;
}

template <class T>
T* deepPointer<T>::operator->() const{
       return ptr;
}

template <class T>
deepPointer<T>::~deepPointer(){
    if(ptr)
        delete ptr;
}

template <class T>
bool deepPointer<T>::operator==(const deepPointer& dptr) const{
    return *ptr==*(dptr.ptr);
}

template <class T>
bool deepPointer<T>::operator!=(const deepPointer& dptr) const{
    return *ptr!=*(dptr.ptr);
}

template<class T>
bool deepPointer<T>::operator<(const deepPointer& dptr) const{
    return *ptr<*(dptr.ptr);
}

template<class T>
bool deepPointer<T>::operator>(const deepPointer& dptr) const{
    return *ptr>*(dptr.ptr);
}

template<class T>
deepPointer<T>::operator T *() const
{
    return ptr;
}

#endif
