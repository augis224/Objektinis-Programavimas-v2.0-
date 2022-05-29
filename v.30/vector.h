#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template <class T>
class Vector {
public: //interfeisas
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    //RULE OF THREE
    //konstruktoriai
    Vector() { create(); }                                                      //SUKURTI: create bus atsakingas uz atminties isskyrima
    explicit Vector(size_type n, const T& val = T{}) { create(n, val); }        //explicit uztikrina, kad veiktu Vector<int> vi(100), o Vector<int> vi = 100 neveiktu
    //copy konstruktorius
    Vector(const Vector& v) { create(v.begin(), v.end()); }                     //SUKURTI: kita create() versija
    //priskyrimo operatorius
    Vector& operator=(const Vector&);
    //destruktorius
    ~Vector() { uncreate(); }                                                   //SUKURTI: uncreate()

    //FUNKCIJOS
    //iteravimas
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    //push_back() realizacija
    void push_back(const T& val){
        if (avail == limit)                                                     //isskirti vietos, jei reikia
            grow();                                                             //SUKURITI: reikia realizuoti
        unchecked_append(val);                                                  //ideti nauja elementa
    }

    //size funckija
    size_type size() const { return avail - data; }

    //begin ir end persidengiancios funkcijos, priklausomai nuo to, ar Vector yra const
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    //realizacija
    iterator data;                                                              //kaip buvo anksciau
    iterator avail;                                                             //pirmasis Vector el.
    iterator limit;                                                             //pirmasis po paskutiniojo Vector el.

    // atminties isskyrimo valdymui
    std::allocator<T> alloc;                                                    //objektas atminties valdymui

    // isskirti atminti (array) ir ja inicializuoti
    void create() ;
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // sunaikinti elementus array ir atlaisvinti atminti
    void uncreate();

    // pagalbines funkcijos push_back realizacijai
    void grow();
    void unchecked_append(const T&);
};


#endif // VECTOR_H_INCLUDED
