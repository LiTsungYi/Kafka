#pragma once

#include <string>
#include <fstream>

namespace Kafka::Stream
{

class IFileStream
{
public:
    IFileStream();
    virtual ~IFileStream();

    bool OpenFile( const std::wstring& fileName, bool binary );
    bool OpenFile( const std::string& fileName, bool binary );
    void CloseFile();
    bool IsOpened() const;

private:
    virtual std::ios_base::openmode GetOpenFileMode() = 0;

protected:
    std::fstream m_stream;

};

}  // namespace Kafka::Stream
