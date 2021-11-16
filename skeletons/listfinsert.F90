!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listf.F90 : linked list basics in Fortran
!***
!****************************************************************


Program LinkedList

  implicit none

  type node
     integer :: value
     type(node),pointer :: next
  end type node

  type list
     type(node),pointer :: head
  end type list
  
  type(list) :: the_list
  type(node),pointer :: node_ptr

  nullify(the_list%head)

  allocate(node_ptr); node_ptr%value = 1
  call insert(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 5
  call insert(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 3
  call insert(the_list,node_ptr)

  call print(the_list)

contains
  
  subroutine insert( the_list,new_node )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    type(node),intent(inout),pointer :: new_node
    ! local
    type(node),pointer :: current,previous

    if (.not.associated(the_list%head)) then
       nullify(new_node%next)
       the_list%head => new_node
    else

    end if
    
  end subroutine insert
  
  integer function length( the_list )
    implicit none
    type(list),intent(in) :: the_list
    ! local
    type(node),pointer :: current

    if (.not.associated(the_list%head)) then
       length = 0
    else
       current => the_list%head       
       do
          length = length+1
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
  end function length

  subroutine print(the_list)
    implicit none
    type(list),intent(in) :: the_list
    type(node),pointer :: current

    write(*,'("List: [ ")',advance="no")
    if (associated(the_list%head)) then
       current => the_list%head
       do while (associated(current))
          write(*,'(i1",")',advance="no") current%value
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
    write(*,'(x"]")')

  end subroutine print
  
end Program LinkedList
