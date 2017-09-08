#pragma once

#include <iterator>
#include <tuple>

namespace Util
{
  namespace Internal 
  {
    template<typename... Ts>
    struct _typelist
    {
      template<typename T> using prepend = _typelist<T, Ts...>;
    };
   
    template<typename T, typename U, T... axes>
    struct _transform
    {
      using types = _typelist<>;
    };

    template<typename T, typename U, T axis, T... axes>
    struct _transform<T, U, axis, axes...>
    {
      using types = typename _transform<T, U, axes...>::types::template prepend<U>;
    };
    
    template<typename T, T axis, T... axes>
    struct _index;

    template<typename T, T axis, T... axes>
    struct _index<T, axis, axis, axes...>: std::integral_constant<size_t, 0> {};

    template<typename T, T axis_A, T axis_B, T... axes>
    struct _index<T, axis_A, axis_B, axes...>: std::integral_constant<size_t, _index<T, axis_A, axes...>::value + 1> {};

    template<typename T> struct tt_impl {};

    template<typename... Ts>
    struct tt_impl<_typelist<Ts...>>: public std::tuple<Ts...>
    {
      template<typename... Args>
      tt_impl(Args&&... values): std::tuple<Ts...>(std::forward<Args>(values)...) {}

      tt_impl(std::tuple<Ts...> &&other): std::tuple<Ts...>(other) {};
    };

    template<typename F, typename T, typename U, typename E, E... axes>
    struct _tt_functor
    {
      static std::tuple<> apply(T &a, T &b)
      {
        return {};
      } 
    };

    template<typename F, typename T, typename U, typename E, E axis, E... axes>
    struct _tt_functor<F, T, U, E, axis, axes...>
    {
      static auto apply(T &a, T &b)
      {
        F f;
        U val_a = a.template get<axis>();
        U val_b = b.template get<axis>();
        U val = f(val_a, val_b);
        std::tuple<U> dest = { val };
        auto tail = _tt_functor<F, T, U, E, axes...>::apply(a, b);
        return std::tuple_cat(dest, tail);
      }
    };

    template<typename U>
    struct sum
    {
      U operator()(U &a, U &b)
      {
        return a + b;
      }
    };

    template<typename U>
    struct sub
    {
      U operator()(U &a, U &b)
      {
         return a - b;
      }
    };
  }

  template<typename T, typename U, T... vals>
  struct tagged_tuple: Internal::tt_impl<typename Internal::_transform<T, U, vals...>::types>
  {

    using type = tagged_tuple<T, U, vals...>;

    template<typename... Args>
    tagged_tuple(Args&&... values): Internal::tt_impl<typename Internal::_transform<T, U, vals...>::types>(std::forward<Args>(values)...) {} 

    template<T val>
    U get()
    {
      return std::get<Internal::_index<T, val, vals...>::value>(*this);
    }

    type operator+(type& rhs)

    {
      return Internal::_tt_functor<Internal::sum<U>, type, U, T, vals...>::apply(*this, rhs);
    }

    type operator-(type& rhs)
    {
      return Internal::_tt_functor<Internal::sub<U>, type, U, T, vals...>::apply(*this, rhs);
    }

    template<T val>
    size_t idx()
    {
      return Internal::_index<T, val, vals...>::value;
    }
  };
}
