#pragma once

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
      using types = Internal::_typelist<>;
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
    struct tt_impl<Internal::_typelist<Ts...>>: public std::tuple<Ts...>
    {
      template<typename... Args>
      tt_impl(Args&&... values): std::tuple<Ts...>(std::forward<Args>(values)...) {}
    };


  }

  template<typename T, typename U, T... vals>
  struct tagged_tuple: Internal::tt_impl<typename Internal::_transform<T, U, vals...>::types>
  {

    template<typename... Args>
    tagged_tuple(Args&&... values): Internal::tt_impl<typename Internal::_transform<T, U, vals...>::types>(std::forward<Args>(values)...) {} 

    template<T val>
    U get()
    {
      return std::get<Internal::_index<T, val, vals...>::value>(*this);
    }

    auto operator+(tagged_tuple<T, U, vals...>& rhs)

    {
      /* TODO: Implement */
      return *this;
    }

    template<T val>
    size_t idx()
    {
      return Internal::_index<T, val, vals...>::value;
    }
  };
}
