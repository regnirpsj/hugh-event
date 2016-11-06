// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/events/base.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_EVENTS_BASE_HPP)

#define HUGH_EVENTS_BASE_HPP

// includes, system

#include <functional> // std::function<>

// includes, project

#include <hugh/event/export.h>
#include <hugh/support/chrono.hpp>
#include <hugh/support/printable.hpp>

namespace hugh {

  namespace event {
    
    // types, exported (class, enum, struct, union, typedef)

    class HUGH_EVENT_EXPORT base : public support::printable {

    public:

      using time_point                = support::clock::time_point;
      using time_source_function_type = std::function<time_point ()>;

      static time_source_function_type time_source();
      static time_source_function_type time_source(time_source_function_type);

      time_point const& time_stamp() const;

      virtual void notify      () =0;
      virtual void async_notify() =0;
    
      virtual void print_on(std::ostream&) const;

    protected:

      time_point const time_stamp_;
      
      explicit base();
      explicit base(base const&);
      explicit base(base&&);
      virtual ~base();
      
    private:

      static time_source_function_type time_source_; // dflt: &hugh::support::clock::now

    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace event {
  
} // namespace hugh {

#endif // #if !defined(HUGH_EVENTS_BASE_HPP)
