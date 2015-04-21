#pragma once

#include <string>
#include <fstream>

namespace Kafka
{
    class IFileStream
    {
    public:
        IFileStream();
        virtual ~IFileStream();

        bool OpenFile( const std::string& fileName, bool binary );
        void CloseFile();
        bool IsOpened() const;

        virtual void Seek( size_t value ) = 0;
        virtual void Skip( size_t value ) = 0;

    protected:
        virtual std::ios_base::openmode GetOpenFileMode()
        {
            return  std::ios_base::in;
        }

        std::fstream m_stream;

    };

}