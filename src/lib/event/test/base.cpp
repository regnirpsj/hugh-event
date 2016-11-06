// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/event/test/base.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <hugh/event/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class event : public hugh::event::base {

  public:

    explicit event()
      : hugh::event::base()
    {
      TRACE("hugh::event::test::<unamed>::event::event");
    }

     /* virtual */ void notify()
    {
      TRACE("hugh::event::test::<unamed>::event::notify");
    }

    /* virtual */ void async_notify()
    {
      TRACE("hugh::event::test::<unamed>::event::async_notify");
    }
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_event_base_ctor)
{
  TRACE("test_hugh_event_base_ctor");
  
  event const e;
  
  BOOST_CHECK       (hugh::support::clock::now() > e.time_stamp());
  BOOST_TEST_MESSAGE(e);
}

BOOST_AUTO_TEST_CASE(test_hugh_event_base_time_source_get)
{  
  TRACE("test_hugh_event_base_time_source_get");

  BOOST_CHECK(nullptr != event::time_source());
}

BOOST_AUTO_TEST_CASE(test_hugh_event_base_time_source_set)
{
  TRACE("test_hugh_event_base_time_source_set");

  event::time_source(nullptr);
  
  BOOST_CHECK(nullptr != event::time_source());
}

BOOST_AUTO_TEST_CASE(test_hugh_event_base_notify)
{
  TRACE("test_hugh_event_base_notify");

  event().notify();
  
  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_hugh_event_base_async_notify)
{
  TRACE("test_hugh_event_base_async_notify");

  event().async_notify();
  
  BOOST_CHECK(true);
}
