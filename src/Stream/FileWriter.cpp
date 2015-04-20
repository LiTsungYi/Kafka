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
        // �ɮץ����}��
        assert( true == m_fileOpened && "�ɮץ����}��" );

        // �첾�����j��ε��� 0
        assert( 0 <= offset && "�첾�����j��ε��� 0" );

        // Ū�� byte �ƥ����j�� 0
        assert( 0 < bytes && "Ū�� byte �ƥ����j�� 0" );

        // buffer ���i�H�� NULL
        assert( NULL != buf && "buffer ���i�H�� NULL" );

        // buffer �j�p�����j��ε���Ū�� bytes
        assert( bufSize >= bytes && "buffer �j�p�����j��ε���Ū�� bytes" );

        if ( 0 == fseek( m_file, offset, SEEK_SET ) )
        {
            // Ū���r��
            return fread( buf, bytes, 1, m_file );
        }
        else
        {
            // �L�k�����w��m
            return 0;
        }

    }

    size_t FileWriter::SetByte( size_t offset, size_t bytes, const void* buf, size_t bufSize )
    {
        // �ɮץ����}��
        assert( true == m_fileOpened && "�ɮץ����}��" );

        // �첾�����j��ε��� 0
        assert( 0 <= offset && "�첾�����j��ε��� 0" );

        // �g�J byte �ƥ����j�� 0
        assert( 0 < bytes && "�g�J byte �ƥ����j�� 0" );

        // buffer ���i�H�� NULL
        assert( NULL != buf && "buffer ���i�H�� NULL" );

        // buffer �j�p�����j��ε���g�J bytes
        assert( bufSize >= bytes && "buffer �j�p�����j��ε���Ū�� bytes" );

        if ( 0 == fseek( m_file, offset, SEEK_SET ) )
        {
            // �g�J�r��
            return fwrite( buf, bytes, 1, m_file );
        }
        else
        {
            // �L�k�����w��m
            return 0;
        }
    }
} // namespace Kafka
