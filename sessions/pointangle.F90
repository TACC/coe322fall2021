!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** type.F90 : fortran types, definition, use, parameter passing
!***
!****************************************************************

Program size
  implicit none

  type point
     real :: x,y
  end type point

  type(point) :: p1,p2
  p1 = point(2.5, 3.7)

  p2 = p1
  print *,p2%x,p2%y
  
  print *,"Length:",length(p2)
  print *,"Angle:",angle(p2)
  
contains
  ! Esc x f90-mode : put emacs in fortran90 mode
  ! C-space : set mark	
  ! go to end of block
  ! ESC w : copy everything between mark & cursor
  ! C-y : paste
  real(4) function length(p)
    implicit none
    type(point),intent(in) :: p
    length = sqrt( &
         p%x**2 + p%y**2 )
  end function length
  
  real(4) function angle(p)
    implicit none
    type(point),intent(in) :: p
    angle = atan( p%y/p%x )
  end function angle
  
end Program size
