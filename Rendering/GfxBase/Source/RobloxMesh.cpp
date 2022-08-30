#include "GfxBase/RobloxMesh.h"

#include <sstream>

std::string RobloxMesh::Write()
{
	struct
	{
		uint16_t headerSize;
		uint8_t vertexSize;
		uint8_t faceSize;
		uint32_t vertexCount;
		uint32_t faceCount;
	} header;

	header.headerSize = sizeof(header);
	header.vertexSize = sizeof(Vertex);
	header.faceSize = sizeof(Face);
	header.vertexCount = (uint32_t)vertices.size();
	header.faceCount = (uint32_t)faces.size();

	std::stringstream stream;

	stream << "version 2.00" << std::endl;
	stream.write((char*)&header, sizeof(header));
	stream.write((char*)vertices.data(), vertices.size() * sizeof(Vertex));
	stream.write((char*)faces.data(), faces.size() * sizeof(Face));

	return stream.str();
}