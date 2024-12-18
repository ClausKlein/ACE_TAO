#ifndef TAO_ANY_ARRAY_IMPL_T_CPP
#define TAO_ANY_ARRAY_IMPL_T_CPP

#include "tao/AnyTypeCode/Any_Array_Impl_T.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Unknown_IDL_Type.h"
#include "tao/AnyTypeCode/Marshal.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/debug.h"
#include "tao/CDR.h"
#include "tao/SystemException.h"

#include "ace/Auto_Ptr.h"

#if !defined (__ACE_INLINE__)
# include "tao/AnyTypeCode/Any_Array_Impl_T.inl"
#endif /* ! __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename T_slice, typename T_forany>
TAO::Any_Array_Impl_T<T_slice, T_forany>::Any_Array_Impl_T (
    _tao_destructor destructor,
    CORBA::TypeCode_ptr tc,
    T_slice * const val)
  : Any_Impl (destructor,
              tc),
    value_ (val)
{
}

template<typename T_slice, typename T_forany>
TAO::Any_Array_Impl_T<T_slice, T_forany>::~Any_Array_Impl_T ()
{
}

template<typename T_slice, typename T_forany>
void
TAO::Any_Array_Impl_T<T_slice, T_forany>::insert (CORBA::Any & any,
                                                  _tao_destructor destructor,
                                                  CORBA::TypeCode_ptr tc,
                                                  T_slice * const value)
{
  TAO::Any_Array_Impl_T<T_slice, T_forany> *new_impl = 0;
  typedef TAO::Any_Array_Impl_T<T_slice, T_forany> ARRAY_ANY_IMPL;
  ACE_NEW (new_impl,
           ARRAY_ANY_IMPL (destructor,
                           tc,
                           value));
  any.replace (new_impl);
}

template<typename T_slice, typename T_forany>
CORBA::Boolean
TAO::Any_Array_Impl_T<T_slice, T_forany>::extract (const CORBA::Any & any,
                                                   _tao_destructor destructor,
                                                   CORBA::TypeCode_ptr tc,
                                                   T_slice *& _tao_elem)
{
  _tao_elem = 0;

  try
    {
      CORBA::TypeCode_ptr any_tc = any._tao_get_typecode ();
      CORBA::Boolean const _tao_equiv = any_tc->equivalent (tc);

      if (_tao_equiv == false)
        {
          return false;
        }

      TAO::Any_Impl *impl = any.impl ();

      if (!impl->encoded ())
        {
          TAO::Any_Array_Impl_T<T_slice, T_forany> *narrow_impl =
            dynamic_cast <TAO::Any_Array_Impl_T <T_slice, T_forany> *> (impl);

          if (narrow_impl == 0)
            {
              return false;
            }

          _tao_elem = reinterpret_cast <T_slice*> (narrow_impl->value_);
          return true;
        }

      TAO::Any_Array_Impl_T<T_slice, T_forany> *replacement = 0;
      typedef TAO::Any_Array_Impl_T<T_slice, T_forany> ARRAY_ANY_IMPL;
      ACE_NEW_RETURN (replacement,
                      ARRAY_ANY_IMPL (destructor,
                                      any_tc,
                                      T_forany::tao_alloc ()),
                      false);

      std::unique_ptr<TAO::Any_Array_Impl_T<T_slice, T_forany> > replacement_safety (replacement);

      // We know this will work since the unencoded case is covered above.
      TAO::Unknown_IDL_Type * const unk =
        dynamic_cast<TAO::Unknown_IDL_Type *> (impl);

      if (!unk)
        return false;

      // We don't want the rd_ptr of unk to move, in case it is
      // shared by another Any. This copies the state, not the buffer.
      TAO_InputCDR for_reading (unk->_tao_get_cdr ());

      CORBA::Boolean const good_decode =
        replacement->demarshal_value (for_reading);

      if (good_decode)
        {
          _tao_elem = reinterpret_cast <T_slice*> (replacement->value_);
          const_cast<CORBA::Any &> (any).replace (replacement);
          replacement_safety.release ();
          return true;
        }

      // Duplicated by Any_Impl base class constructor.
      ::CORBA::release (any_tc);
    }
  catch (const ::CORBA::Exception&)
    {
    }

  return false;
}

template<typename T_slice, typename T_forany>
CORBA::Boolean
TAO::Any_Array_Impl_T<T_slice, T_forany>::marshal_value (TAO_OutputCDR &cdr)
{
  return (cdr << T_forany (this->value_));
}

template<typename T_slice, typename T_forany>
const void *
TAO::Any_Array_Impl_T<T_slice, T_forany>::value () const
{
  return this->value_;
}

template<typename T_slice, typename T_forany>
void
TAO::Any_Array_Impl_T<T_slice, T_forany>::free_value ()
{
  if (this->value_destructor_)
    {
      (*this->value_destructor_) (this->value_);
      this->value_destructor_ = nullptr;
    }

  this->value_ = nullptr;
  ::CORBA::release (this->type_);
}

template<typename T_slice, typename T_forany>
void
TAO::Any_Array_Impl_T<T_slice, T_forany>::_tao_decode (TAO_InputCDR &cdr)
{
  if (! this->demarshal_value (cdr))
    {
      throw ::CORBA::MARSHAL ();
    }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_ANY_ARRAY_IMPL_T_CPP */
