#ifndef CONTAINER_H
#define CONTAINER_H
//#include <iterator>

template <typename T>
class container{
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo(const T&, nodo* =nullptr);
        void distruggi();
    };
    nodo* first;
    nodo* last;
        int size;
public:
    //costruttori e distruttore
    container(nodo* =nullptr, nodo* =nullptr, unsigned int =0);
    container(container*);
    ~container();
    //metodi della lista, push_back, remove, ...
    void erase_pos (const int); //cancello valore in posizione i
    unsigned int get_pos(const T&); //*
    //const T& element_at_pos(unsigned int);
    bool empty() const; //*controllo se il container è vuoto
    void push_front(const T&); //*aggiunge un elemento all'inizio
    void push_back(const T&); //aggiunge un elemento alla fine
    void pop_back(); //*fa una erase_pos(size-1) rimuove l'ultimo elemento DA VERIFICARE
    void replace_last(int, const T&); //elimina elementi in una certa posizione e ne aggiunge un altro alla fine
    T get_T_at_pos(const int) const;
    int get_size()const; //ritorno IL NUMERO di elementi
    void erase();

    //classe iteratore
    class iterator{
    friend class container<T>;
    private:
        nodo* pointer;
    public:
        iterator(nodo* p=nullptr);

        iterator& operator=(const iterator&);

        iterator& operator++();		//prefisso
        iterator operator++(int);	//postfisso

        bool operator==(const iterator& );
        bool operator!=(const iterator& );

        T& operator*() const;
                nodo* operator->() const;
    };

    class const_iterator{ //aggiungere i const dove servono!!
        friend class container<T>;
    private:
        const nodo* pointer;
    public:
        const_iterator(nodo* p=nullptr);
        const_iterator& operator=(const const_iterator&);
        const_iterator& operator++();
        const_iterator operator++(int);

        bool operator==(const const_iterator& );
        bool operator!=(const const_iterator& );

        const T& operator*() const;
        const nodo* operator->() const;
    };

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};


//NODO
template<typename T>
container<T>::nodo::nodo(const T& i, container::nodo * n): info(i), next(n){}

template<typename T>
void container<T>::nodo::distruggi()
{
    if(next) next->distruggi();
    delete this;
}

//ITERATOR
template<typename T>
container<T>::iterator::iterator(container::nodo *p): pointer(p){}

template<typename T>
typename container<T>::iterator & container<T>::iterator::operator=(const container::iterator & i)
{
    pointer=i.pointer;
    return *this;
}

template<typename T>
typename container<T>::iterator &container<T>::iterator::operator++()
{
    if(pointer)
    pointer=pointer->next;
    return *this;
}

template<typename T>
typename container<T>::iterator container<T>::iterator::operator++(int)
{
    iterator copy(*this);
    ++(*this);
    return copy;
}

template<typename T>
bool container<T>::iterator::operator==(const container::iterator & i)
{
    return i.pointer==pointer;
}

template<typename T>
bool container<T>::iterator::operator!=(const container::iterator & i)
{
    return i.pointer!=pointer;//oppure return !(i.pointer==pointer), ma forse è meglio utilizare !=
}

template<typename T>
T &container<T>::iterator::operator*() const
{
    return pointer->info;
}

template<typename T>
typename container<T>::nodo *container<T>::iterator::operator->() const
{
    return pointer;
}

//CONST ITERATOR
template<typename T>
container<T>::const_iterator::const_iterator(container::nodo *p): pointer(p){}

template<typename T>
typename container<T>::const_iterator & container<T>::const_iterator::operator=(const container::const_iterator & i)
{
    pointer=i.pointer;
    return *this;
}

template<typename T>
typename container<T>::const_iterator &container<T>::const_iterator::operator++()
{
    if(pointer)
        pointer=pointer->next;
    return *this;
}

template<typename T>
typename container<T>::const_iterator container<T>::const_iterator::operator++(int)
{
    iterator copy(*this);
    ++(*this);
    return copy;
}

template<typename T>
bool container<T>::const_iterator::operator==(const container::const_iterator & i)
{
    return i.pointer==pointer;
}

template<typename T>
bool container<T>::const_iterator::operator!=(const container::const_iterator & i)
{
    return i.pointer!=pointer;//oppure return !(i.pointer==pointer), ma forse è meglio utilizare !=
}

template<typename T>
const T &container<T>::const_iterator::operator*() const
{
    return pointer->info;
}

template<typename T>
const typename container<T>::nodo *container<T>::const_iterator::operator->() const
{
    return pointer;
}

//CONTAINER
template<typename T>
typename container<T>::iterator container<T>::begin()
{
    return iterator(first);
    /*
    iterator aux(first);
    return aux;
    */
}

template<typename T>
typename container<T>::iterator container<T>::end()
{
    return iterator(nullptr);
}

template<typename T>
container<T>::container(container::nodo *f, container::nodo *l, unsigned int s): first(f), last(l), size(s){}

template<typename T>
container<T>::container(container *c)
{
    auto temp=c->begin();
    while(temp!=c->end())
    {
        this->insert(*c);
    }
}

template<typename T>
container<T>::~container()
{
    if(first) first->distruggi();
    size=0;
}

template<typename T>
void container<T>::erase_pos(int i)//non uso unsigned int perché non credo che un u.int possa essere 0
{
    if(empty())
        return;

    if(!first->next){
        if(i==0){
            delete first;
            first=nullptr;
            size-=1;
            return;
        }
    }
    else {
        nodo* prec=first;
        nodo* corr=first->next;

        if(i==0){
            first=first->next;
            prec->next=nullptr;
            delete prec;
            size-=1;
            return;
        }

        for(int x=1; corr->next && x<i; x++){
            prec=prec->next;
            corr=corr->next;
        }

        if(corr->next) {
            prec->next=corr->next;
            corr->next=nullptr;
            delete corr;
            size-=1;
            return;
        }
        else {
            prec->next=nullptr;
            last=prec;
        }
        delete corr;
        size-=1;
        return;
    }
    return;
}

template<class T>
void container<T>::erase()
{
    if (first){
        first->distruggi();
        last = nullptr;
    }
}

template<typename T>
unsigned int container<T>::get_pos(const T & n)//PRE: nella lista esiste un nodo con valore n
{
    unsigned int i=0;
    nodo*tmp=first;

    bool found=false;
    while(!found && tmp)
    {
        if(tmp->info==n)
            found=true;
        else
        {
            tmp=tmp->next;
            i+=1;
        }
    }
    return i;
}

template<typename T>
bool container<T>::empty() const
{
    return size==0;
}

template<typename T>
void container<T>::push_front(const T & n)
{
   if(!first)
   {
       first=last=new nodo(n, nullptr);
       size=1;
   }
   else
   {
       first=new nodo(n, first);
       size+=1;
   }
}

template<typename T>
void container<T>::push_back(const T & n)
{
    if(!first)
   {
       first=last=new nodo(n, nullptr);
       size=1;
   }
   else
   {
        nodo*new_last=new nodo(n,nullptr);
        last->next=new_last;
        last=new_last;
        size+=1;
   }
}

template<typename T>
void container<T>::pop_back() // per fare questa uso la erase, che elimina un elemento in una posizione nota
{
    if(this==last)//caso base: ho un solo elemento nella lista
    {
        delete last;
        first=last=nullptr;
        size=0;
        return;
    }
    nodo* prec=first, *curr=first->next;
    while(curr->next)
    {
        curr=curr->next;
        prec=prec->next;
    }
    //prec punterà al nuovo ultimo nodo
    delete last;
    prec->next=nullptr;
    last=prec;
    size-=1;
}

template<typename T>
void container<T>::replace_last(int i, const T& m)
{
    erase_pos(i);
    push_back(m);
}

template<typename T>
T container<T>::get_T_at_pos(const int i) const
{
    if(!first->next){
        if(i==0){
            return first->info;
        }
    }
    else{
        nodo* curr=first->next;

        if(i==0){
            return first->info;
        }

        for(int x=1; curr->next && x<i; x++){
            curr=curr->next;
        }

        if(curr){
            return curr->info;
        }
    }
    T tmp;
    return tmp;
}

template<typename T>
int container<T>::get_size() const
{
    return size;
}

#endif
