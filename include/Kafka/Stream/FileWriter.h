#pragma once

#include <string>

namespace Kafka
{
    class FileWriter
    {
    public:
        FileWriter();
        ~FileWriter();

        bool OpenFile( int index );
        void CloseFile();
        bool IsOpened();

        size_t GetByte( size_t offset, size_t bytes, void* buf, size_t bufSize );
        size_t SetByte( size_t offset, size_t bytes, const void* buf, size_t bufSize );

    protected:
        bool m_fileOpened;
        FILE* m_file;

        static const unsigned int FILE_NAME_LENGTH = 13;
        static const unsigned int MIN_INDEX = 0;
        static const unsigned int MAX_INDEX = 7;

    };

}