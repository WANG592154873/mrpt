/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#include "io-precomp.h"  // Precompiled headers

#include <mrpt/io/vector_loadsave.h>
#include <mrpt/io/CFileInputStream.h>
#include <mrpt/io/CFileOutputStream.h>

using namespace mrpt;
using namespace mrpt::io;
using namespace std;

bool mrpt::io::loadBinaryFile(
	std::vector<uint8_t>& out_data, const std::string& fileName)
{
	try
	{
		CFileInputStream fi(fileName);
		size_t N = fi.getTotalBytesCount();

		out_data.resize(N);
		if (N)
		{
			size_t NN = fi.ReadBuffer(&out_data[0], N);
			return NN == N;
		}
		else
			return true;
	}
	catch (...)
	{
		return false;
	}
}

bool mrpt::io::vectorToBinaryFile(
	const std::vector<uint8_t>& vec, const std::string& fileName)
{
	try
	{
		mrpt::utils::CFileOutputStream of(fileName);
		if (!vec.empty()) of.WriteBuffer(&vec[0], sizeof(vec[0]) * vec.size());
		return true;
	}
	catch (...)
	{
		return false;
	}
}