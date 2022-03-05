// TO DO:  Write file header.

// TO DO:  Update the member function comments to reflect your own style.

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
    CELL** Rows;     // C array of linked lists
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
            for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
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
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the vector.
    //
    virtual ~Grid() {
        
        // TO DO:  Write this destructor.
        
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
        
        // TO DO:  Write this copy constructor.
        
    }
    
    //
    // copy operator=
    //
    // Called when you assign one vector into another, i.e. this = other;
    //
    Grid& operator=(const Grid& other) {
        Grid<T> temp;
        
        // TO DO:  Write this copy operator.
        
        return temp;  // TO DO:  update this, it is only here so code compiles.
    }
    
    //
    // numrows
    //
    // Returns the # of rows in the Grid.  The indices for these rows
    // are 0..numrows-1.
    //
    size_t numrows() const {
        
        // TO DO:  Write this function.
        
        return 0;  // TO DO:  update this, it is only here so code compiles.
    }
    
    
    //
    // numcols
    //
    // Returns the # of columns in row r.  The indices for these columns
    // are 0..numcols-1.  For now, each row will have the same number of columns.
    //
    size_t numcols(size_t r) const {
        
        // TO DO:  Write this function.
        
        return 0;  // TO DO:  update this, it is only here so code compiles.
        
    }
    
    
    //
    // size
    //
    // Returns the total # of elements in the grid.
    //
    size_t size() const {
        
        // TO DO:  Write this function.
        
        return 0;  // TO DO:  update this, it is only here so code compiles.
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
        T temp;
        
        
        // TO DO:  Write this function.
        
        
        return temp;  // TO DO:  update this, it is only here so code compiles.
    }
    
    //
    // _output
    //
    // Outputs the contents of the grid; for debugging purposes.  This is not
    // tested.
    //
    void _output() {
        
        // TO DO:  Write this function.
        
    }
    
};

