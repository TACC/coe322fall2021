!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** pointexample.F90 : example for the textbook exercise
!****
!****************************************************************

Module PointClass
  Type,public :: Point
     real(8) :: x,y
   contains
     procedure, public :: &
        distance,add
  End type Point
contains
  !! ... distance function ...
  real(8) function distance(me,other)
    implicit none
    class(Point),intent(in) :: me
    type(Point),intent(in) :: other
    real(8) :: dx,dy
    dx = me%x-other%x; dy = me%y-other%y
    distance = sqrt( dx**2 + dy**2 )
  end function distance

  !! sum function

  !! option1 for return syntax:
  !! Type(Point) function add(p,q)
  !! .....
  !! add = Point(....)
  
  !! other syntax:
  function add(p,q) result(sumpoint)
    implicit none
    Class(Point),Intent(in) :: p
    Type(Point),Intent(in) :: q
    Type(Point) :: sumpoint
    sumpoint = Point(p%x+q%x,p%y+q%y)
  end function add

End Module PointClass


Program PointTest
  use PointClass
  implicit none
  type(Point) :: p1,p2,psum

  p1 = point(1.d0,1.d0)
  p2 = point(4.d0,5.d0)
  print *,"Distance:",&
      p1%distance(p2)

  psum = p1%add(p2)
  print *,"Sum"
  ! 2x : two spaces
  ! i4 : integer of 4 positions
  ! fw.d : float of width w with d behind the decimal
  ! ew.d.e ?
  ! ( ... ) : grouping
  ! 2whatever : repetition

  print '( 3( i2,":",1x,2(f5.3,1x),"; " ) )',1,p1,2,p2,3,psum
  print 10,1,p1,2,p2,3,psum
10 format( 3( i2,":",1x,2(f5.3,1x),"; " ) )

  !! need to look up syntax for opening a file: WRONG open(7,"pointout")
  !! write to "unit" 7
  write(7,10) 1,p1,2,p2,3,psum

End Program PointTest

