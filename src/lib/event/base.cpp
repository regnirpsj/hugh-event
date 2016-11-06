// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/event/base.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/event/base.hpp"

// includes, system

#include <ostream>   // std::ostream
#include <stdexcept> // std::logic_error

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  hugh::event::base::time_source_function_type const dflt_time_source(hugh::support::clock::now);
  
  // functions, internal

} // namespace {

namespace hugh {

  namespace event {
    
    // variables, exported

    /* static */ base::time_source_function_type base::time_source_(dflt_time_source);

    // functions, exported

    /* static */ base::time_source_function_type
    base::time_source()
    {
      TRACE("hugh::event::base::time_source(get)");

      return time_source_;
    }

    /* static */ base::time_source_function_type
    base::time_source(time_source_function_type a)
    {
      TRACE("hugh::event::base::time_source(set)");

      time_source_function_type result(time_source_);

      time_source_ = a;

      if (nullptr == time_source_) {
        time_source_ = dflt_time_source;
      }
      
      return result;
    }

    base::time_point const&
    base::time_stamp() const
    {
      TRACE("hugh::event::base::time_stamp");

      return time_stamp_;
    }

    /* virtual */ void
    base::notify()
    {
      TRACE("hugh::event::base::notify");

      throw std::logic_error("pure virtual function 'hugh::event::base::notify' called");
    }

    /* virtual */ void
    base::async_notify()
    {
      TRACE("hugh::event::base::async_notify");

      throw std::logic_error("pure virtual function 'hugh::event::base::async_notify' called");
    }

    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("hugh::event::base::print_on");

      os << '[' << time_stamp_ << ']';
    }
    
    /* explicit */
    base::base()
      : time_stamp_(time_source_())
    {
      TRACE("hugh::event::base::base(dflt)");
    }

    /* explicit */
    base::base(base const& a)
      : time_stamp_(a.time_stamp_)
    {
      TRACE("hugh::event::base::base(copy)");
    }
    
    /* explicit */
    base::base(base&& a)
      : time_stamp_(a.time_stamp_)
    {
      TRACE("hugh::event::base::base(move)");
    }
    
    /* virtual */
    base::~base()
    {
      TRACE("hugh::event::base::~base");
    }

  } // namespace event {
  
} // namespace hugh {
