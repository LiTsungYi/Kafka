#include "Pch.h"

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "Kafka\Stream\FileWriter.h"

namespace Kafka
{

    FileWriter::FileWriter() : m_fileOpened( false ), m_file( NULL )
    {

    }

    FileWriter::~FileWriter()
    {
        if ( m_fileOpened )
        {
            if ( NULL != m_file )
            {
                fclose( m_file );
            }
        }
    }

    bool FileWriter::OpenFile( int index )
    {
        // Range check
        if ( index >= MIN_INDEX && index <= MAX_INDEX )
        {
            char tempFileName[ FILE_NAME_LENGTH ];

            _snprintf_s( tempFileName, FILE_NAME_LENGTH, FILE_NAME_LENGTH - 1, "SAVEDAT%d.DK4", index );
            tempFileName[ FILE_NAME_LENGTH - 1 ] = '\0';

            if ( 0 == fopen_s( &m_file, tempFileName, "r+b" ) )
            {
                // Open file success
                m_fileOpened = true;
            }
        }

        return m_fileOpened;
    }

    void FileWriter::CloseFile()
    {
        if ( m_fileOpened )
        {
            if ( NULL != m_file )
            {
                fclose( m_file );
            }
        }
    }

    bool FileWriter::IsOpened()
    {
        return m_fileOpened;
    }

    size_t FileWriter::GetByte( size_t offset, size_t bytes, void* buf, size_t bufSize )
    {
        // 檔案必須開啟
        assert( true == m_fileOpened && "檔案必須開啟" );

        // 位移必須大於或等於 0
        assert( 0 <= offset && "位移必須大於或等於 0" );

        // 讀取 byte 數必須大於 0
        assert( 0 < bytes && "讀取 byte 數必須大於 0" );

        // buffer 不可以為 NULL
        assert( NULL != buf && "buffer 不可以為 NULL" );

        // buffer 大小必須大於或等於讀取 bytes
        assert( bufSize >= bytes && "buffer 大小必須大於或等於讀取 bytes" );

        if ( 0 == fseek( m_file, offset, SEEK_SET ) )
        {
            // 讀取字元
            return fread( buf, bytes, 1, m_file );
        }
        else
        {
            // 無法找到指定位置
            return 0;
        }

    }

    size_t FileWriter::SetByte( size_t offset, size_t bytes, const void* buf, size_t bufSize )
    {
        // 檔案必須開啟
        assert( true == m_fileOpened && "檔案必須開啟" );

        // 位移必須大於或等於 0
        assert( 0 <= offset && "位移必須大於或等於 0" );

        // 寫入 byte 數必須大於 0
        assert( 0 < bytes && "寫入 byte 數必須大於 0" );

        // buffer 不可以為 NULL
        assert( NULL != buf && "buffer 不可以為 NULL" );

        // buffer 大小必須大於或等於寫入 bytes
        assert( bufSize >= bytes && "buffer 大小必須大於或等於讀取 bytes" );

        if ( 0 == fseek( m_file, offset, SEEK_SET ) )
        {
            // 寫入字元
            return fwrite( buf, bytes, 1, m_file );
        }
        else
        {
            // 無法找到指定位置
            return 0;
        }
    }
} // namespace Kafka
