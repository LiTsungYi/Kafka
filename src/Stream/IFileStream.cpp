#include "Pch.h"

#include "Kafka\Stream\IFileStream.h"

namespace Kafka
{
    IFileStream::IFileStream()
    {
    }

    IFileStream::~IFileStream()
    {
        CloseFile();
    }

    bool IFileStream::OpenFile( const std::string& fileName, bool binary )
    {
        std::ios_base::openmode mode = GetOpenFileMode();
        m_stream.open( fileName, mode | std::ios_base::out | std::ios_base::binary );
        return IsOpened();
    }

    void IFileStream::CloseFile()
    {
        if ( IsOpened() )
        {
            m_stream.close();
        }
    }

    bool IFileStream::IsOpened() const
    {
        return m_stream.is_open();
    }
} // namespace Kafka
