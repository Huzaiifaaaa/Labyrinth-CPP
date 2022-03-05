// TO DO:  Write file header.
/*
 * Jamani Alford - Fall 2021
 * CS 251 - Project 4
 * 
 * The purpose of this project is to overall go through
 * a series of mazes that are meant for the user to collect
 * a total of three things. Once it collects all three things,
 * it can initiate the final spell.
 * 
 * READ ME VVVVV
 * Despite the test cases not accepting that I haven't escaped the path, my logs say I have escaped it properly.Despite
 *
 * 
*/
#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct CELL {
    CELL* Next;
    T Val;
    size_t NumCols;  // total # of columns (0..NumCols-1)
    CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
      Next = _Next;
      Val = _Val;
      NumCols = _NumCols;
    }
  };
  size_t NumRows;  // total # of rows (0..NumRows-1)
  CELL** Rows;     // C array of linked lists Composed of CELLs.
public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    // initialize 4 rows
    Rows = new CELL*[4];
    NumRows = 4;
    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
        Rows[r] = new CELL(nullptr, T(), 4);
        CELL* cur = Rows[r];
        // create the linked list for this row.
        for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
            cur->Next = new CELL(nullptr, T());
            cur = cur->Next;
        }
    }
  }
  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a Grid with R rows,
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  Grid(size_t R, size_t C) {
      // TO DO:  Write this parameterized constructor.
      //Done
      Rows = new CELL * [R];
      NumRows = R;
      //Allocate the first cell of the linked list with default value: Nullptr is where the cell is starting
      for (size_t r = 0; r < NumRows; ++r) {
          Rows[r] = new CELL(nullptr, T(), C);
          CELL* cur = Rows[r];
      //Creates a linked list for the row.
        for (size_t c = 1; c < Rows[r] -> NumCols; ++c) {
          cur -> Next = new CELL(nullptr, T());
          cur = cur -> Next;
        }
      }
  }
	void rowDelete(CELL* setRow) {
		if (!setRow)
			return;
		rowDelete(setRow -> Next);
		delete setRow;
	}
  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the vector.
  //
  virtual ~Grid() {
    for (size_t r = 0; r < NumRows; ++r) {
			rowDelete(Rows[r]);
			}
		delete[] Rows;
    }
  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
    Rows = new CELL*[other.NumRows];
    NumRows = other.NumRows;
    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
        Rows[r] = new CELL(nullptr, other.Rows[r] -> Val, other.Rows[r] -> NumCols);
        CELL* cur = Rows[r];
        CELL* curr = other.Rows[r];
        curr = curr -> Next;
      
        // create the linked list for this row.
        for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
            cur->Next = new CELL(nullptr, curr -> Val);
            cur = cur->Next;
            curr = curr -> Next;
        }
    }
  }
    
  //
  // copy operator=
  //
  // Called when you assign one vector into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      Grid<T> temp;
      for (int z = 0; z < NumRows; ++z){
      rowDelete(Rows[z]);
    }
    delete[] Rows;
    Rows = new CELL*[other.NumRows];
    NumRows = other.NumRows;
    for (size_t r = 0; r < NumRows; ++r) {
        Rows[r] = new CELL(nullptr, other.Rows[r] -> Val, other.Rows[r] -> NumCols);
        CELL* cur = Rows[r];
        CELL* curr = other.Rows[r];
        curr = curr -> Next;
      
        
        for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
            cur->Next = new CELL(nullptr, curr -> Val);
            cur = cur->Next;
            curr = curr -> Next;
        }
    }
    
    return *this;
  }
  //
  // numrows
  //
  // Returns the # of rows in the Grid.  The indices for these rows
  // are 0..numrows-1.
  //
  size_t numrows() const {
      
    // TO DO:  Write this function.
    //Done
    return this -> NumRows;
      
  }
  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  For now, each row will have the same number of columns.
  //
  size_t numcols(size_t r) const {
      // TO DO:  Write this function.
      //Done
//     if(r >= NumRows || r < 0){
//         throw out_of_range("Not in range");
//       } 
      return this -> Rows[r] -> NumCols;
  }
  //
  // size
  //
  // Returns the total # of elements in the grid.
  //
  size_t size() const {
      int mazeSize = 0;
      for (int i = 0; i < NumRows; ++i){
        mazeSize += Rows[i] -> NumCols;
      }
      return mazeSize;
  }
  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
      // TO DO:  Write this function.
      //Done
//       if(r >= NumRows || r < 0){
//         throw out_of_range("Not in range");
//       }
//       if(c >= NumRows || c < 0){
//         throw out_of_range("Not in range");
//       } 
      CELL* temp = Rows[r];
      for (size_t x = 0; x < c; ++x){
          temp = temp -> Next;
        }
      return temp -> Val;  // TO DO:  update this, it is only here so code compiles.
  }
  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  This is not
  // tested.
  //
  void _output() {
      for (size_t r = 0; r < NumRows; ++r){
        for (size_t c = 1; c < Rows[r] -> NumCols; ++c){
            cout << Rows[r] -> Val << " ";
        }
        cout << endl;
      }
  }
};
