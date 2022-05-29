#include "vector.h"

//priskyrimo operatoriaus realizacija
template <class T>
Vector<T>& Vector<T>::operator = (const Vector& rhs){
    //patikriname ar ne lygu
    if (&rhs != this){
        //atlaisviname sena this objekto atminti
        uncreate();
        //perkopijuojame elementus is rhs i lhs (this)
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

//persidengiancios create() realizacijos
template <class T> void Vector<T>::create(){
    data = avail = limit = nullptr;
}
template <class T> void Vector<T>::create(size_type n, const T& val){
    data = alloc.allocate(n);                                                   //grazina ptr i array pirma elementa
    limit = avail = data + n;                                                   //sustato rodykles i vietas
    uninitialized_fill(data, limit, val);                                       //inicializuoja elementus val reiksme
}
template <class T>
    void Vector<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);                                               //isskirti vietos j-i elementams
    limit = avail = uninitialized_copy(i, j, data);                             //nukopijuoja elementus is intervalo
}

//uncreate() realizacija
template <class T> void Vector<T>::uncreate(){
    if (data){
    //sunaikinti (atbuline tvarka) sukonstruotus elementus
        iterator it = avail;
        while (it != data)
        alloc.destroy(--it);
        //atlaisvinti isskirta atminti. Turi buti data != nullptr
        alloc.deallocate(data, limit - data);
    }
    //reset'inam pointer'ius - Vector'ius tuscias
    data = limit = avail = nullptr;
}

//grow() realizacija
template <class T> void Vector<T>::grow(){
    //dvigubai daugiau vietos, nei buvo
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
    //isskirti nauja vieta ir perkopijuoti egzistuojancius elementus
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);
    //atlaisvinti sena vieta
    uncreate();
    //resetint rodykles i naujai isskirta vieta
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

//unchecked_append() realizacija. tariame, kad `avail` pointina i isskirta, bet neinicializuota vieta
template <class T> void Vector<T>::unchecked_append(const T& val) {
 alloc.construct(avail++, val);
}
