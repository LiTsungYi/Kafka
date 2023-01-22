#include "Pch.h"

#include "Kafka/Stream/IFileStream.h"

namespace Kafka::Stream
{

IFileStream::IFileStream()
{}

IFileStream::~IFileStream()
{
    CloseFile();
}

bool IFileStream::OpenFile( const std::wstring& fileName, bool binary )
{
    std::ios_base::openmode mode = GetOpenFileMode();
    if ( binary )
    {
        mode |= std::ios_base::binary;
    }

    m_stream.open( fileName, mode );
    return IsOpened();
}

bool IFileStream::OpenFile( const std::string& fileName, bool binary )
{
    std::ios_base::openmode mode = GetOpenFileMode();
    if ( binary )
    {
        mode |= std::ios_base::binary;
    }

    m_stream.open( fileName, mode );
    return IsOpened();
}

void IFileStream::CloseFile()
{
    if ( IsOpened() )
    {
        m_stream.flush();
        m_stream.close();
    }
}

bool IFileStream::IsOpened() const
{
    return m_stream.is_open();
}

}  // namespace Kafka::Stream
