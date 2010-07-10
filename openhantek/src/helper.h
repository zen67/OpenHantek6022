////////////////////////////////////////////////////////////////////////////////
//
//  OpenHantek
/// \file helper.h
/// \brief Provides miscellaneous helper functions.
//
//  Copyright (C) 2010  Oliver Haag
//  oliver.haag@gmail.com
//
//  This program is free software: you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation, either version 3 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along with
//  this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef HELPER_H
#define HELPER_H


#include <QString>


namespace Helper {
	//////////////////////////////////////////////////////////////////////////////
	/// \enum Unit                                                        helper.h
	/// \brief The various units supported by valueToString.
	enum Unit {
		UNIT_VOLTS, UNIT_DECIBEL,
		UNIT_SECONDS, UNIT_HERTZ,
		UNIT_SAMPLES
	};
	
	QString libUsbErrorString(int error);
	QString valueToString(double value, Unit unit, int precision = -1);
	
	//////////////////////////////////////////////////////////////////////////////
	/// \class DataArray                                                  helper.h
	/// \brief A class template for a simple array with a fixed size.
	template <class T> class DataArray {
		public:
			DataArray(unsigned int size);
			~DataArray();
			
			T *data();
			T operator[](unsigned int index);
			
			unsigned int getSize() const;
		
		protected:
			T *array;
			unsigned int size;
	};
	
	/// \brief Initializes the data array.
	/// \param size Size of the data array.
	template <class T> DataArray<T>::DataArray(unsigned int size) {
		this->array = new T[size];
		for(unsigned int index = 0; index < size; index++)
			this->array[index] = 0;
		this->size = size;
	}
	
	/// \brief Deletes the allocated data array.
	template <class T> DataArray<T>::~DataArray() {
		delete[] this->array;
	}
	
	/// \brief Returns a pointer to the array data.
	/// \return The internal data array.
	template <class T> T *DataArray<T>::data() {
		return this->array;
	}
	
	/// \brief Returns array element when using square brackets.
	/// \return The array element.
	template <class T> T DataArray<T>::operator[](unsigned int index) {
		return this->array[index];
	}
	
	/// \brief Gets the size of the array.
	/// \return The size of the command in bytes.
	template <class T> unsigned int DataArray<T>::getSize() const {
		return this->size;
	}
};


#endif