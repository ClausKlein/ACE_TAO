/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "IORS.h"

ACE_RCSID(tao, IORS, "$Id$")

#if !defined (__ACE_INLINE__)
#include "IORS.i"
#endif /* !defined INLINE */

POA_TAO_IOP::TAO_IOR_Manipulation::TAO_IOR_Manipulation (void)
{
}

// copy ctor
// POA_TAO_IOP::TAO_IOR_Manipulation::TAO_IOR_Manipulation (const TAO_IOR_Manipulation& rhs)
//   :   TAO_Local_ServantBase (rhs)
// {}
//
// skeleton destructor
POA_TAO_IOP::TAO_IOR_Manipulation::~TAO_IOR_Manipulation (void)
{
}

CORBA::Boolean POA_TAO_IOP::TAO_IOR_Manipulation::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/TAO_IOP/TAO_IOR_Manipulation:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_TAO_IOP::TAO_IOR_Manipulation::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/TAO_IOP/TAO_IOR_Manipulation:1.0") == 0)
    return ACE_static_cast (POA_TAO_IOP::TAO_IOR_Manipulation_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_TAO_IOP::TAO_IOR_Manipulation::_interface_repository_id (void) const
{
  return "IDL:omg.org/TAO_IOP/TAO_IOR_Manipulation:1.0";
}


TAO_IOP::TAO_IOR_Manipulation*
POA_TAO_IOP::TAO_IOR_Manipulation::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation (this, stub);
}

void*
POA_TAO_IOP::TAO_IOR_Manipulation::_create_collocated_objref (CORBA::ULong type, TAO_Stub *stub)
{
  return new POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation (this, stub);
}

POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::_tao_collocated_TAO_IOR_Manipulation (
    POA_TAO_IOP::TAO_IOR_Manipulation_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (TAO_IOP,TAO_IOR_Manipulation) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_TAO_IOP::TAO_IOR_Manipulation_ptr POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Object_ptr POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::merge_iors  (
    const TAO_IOP::TAO_IOR_Manipulation::IORList & iors,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::Duplicate,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR
  ))
{
  return this->servant_->merge_iors (
      iors,
      ACE_TRY_ENV
    );

}

CORBA::Object_ptr POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::add_profiles  (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::Duplicate,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR
  ))
{
  return this->servant_->add_profiles (
      ior1,
      ior2,
      ACE_TRY_ENV
    );

}

CORBA::Object_ptr POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::remove_profiles  (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
    TAO_IOP::TAO_IOR_Manipulation::NotFound
  ))
{
  return this->servant_->remove_profiles (
      ior1,
      ior2,
      ACE_TRY_ENV
    );

}

CORBA::ULong POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::is_in_ior  (
    CORBA::Object_ptr ior1,
    CORBA::Object_ptr ior2,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::NotFound
  ))
{
  return this->servant_->is_in_ior (
      ior1,
      ior2,
      ACE_TRY_ENV
    );

}

CORBA::ULong POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation::get_profile_count  (
    CORBA::Object_ptr ior,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList
  ))
{
  return this->servant_->get_profile_count (
      ior,
      ACE_TRY_ENV
    );

}
