#ifndef ITER_HPP
#define ITER_HPP

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
*/

template <typename T , typename H>
void iter(T* array, size_t length, H func)
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
        //func();
    }
}

/*
template <typename T> // in questa function template c'e' solo un tipo generico definito infatti non funziona con datatype diversi passati dai valori di paramentro
void iter(T* array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}
*/
#endif // ITER_HPP
