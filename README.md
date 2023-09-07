#### General description

When processing a client request to the server, our proxy must send a request to the server, receive data from it, then send it to the client. There are two different connections: one between the client and the proxy server, the other between the proxy and the original server. The data transfer speed of these connections may be different. If the data transfer rate to the client is slower than the rate at which the data comes from the server, then it may turn out that the data from the server is accumulating. In order for request processing to work as quickly as possible, in most cases it is desirable to store data in a buffer in memory. However, if data starts to accumulate (a certain limit is exceeded), memory overflow should be avoided and temporary files should be used to store this data.

It is assumed that there are at least two threads. In one stream, a new portion of data comes from the server. On another thread, data is sent to the client and cleared from an in-memory buffer/temporary files

When using an in-memory buffer, unnecessary memory copies should be avoided. To do this, if, for example, there were 16K data in the buffer and 4K were read, then the remaining 12K are not shifted down to the beginning of the buffer, but pointers (offsets) are used to the beginning of the unread data and the end of the data to be read

In the case of using temporary files, we should also avoid creating very large files. For example, if the server returns data with a size of 4GB, then it would be wrong to receive a temporary file of this size when transferring data using, for example, such an algorithm:
- created a file of zero size
- 64K came from the server and we wrote it to a file
- 64K came from the server and we wrote it to a file
- read 64K, sent to the client, noted to themselves that the next portion of data is at offset 64K
- 64K came from the server and we wrote it to a file
- 64K came from the server and we wrote it to a file
- read 64K, send it to the client, mark yourself that the next portion of data is at offset 128K
- ...
In this case, the file is constantly growing

Thus, it is logical to create files (chunks) no larger than some given size (for example 16M) and delete these files when the data from them is sent to the client. Thus, if the size of the returned data is 4GB and the data return rate to the client is two times less than the data processing rate, we will receive at some point a maximum of 2GB of data on the disk. But in a real situation, the transfer rate to the client works quickly (except for situations when the client is temporarily not ready to receive data). Usually, the transfer rate to the client is higher than the data transfer rate from the server, and if the data has accumulated in memory or in temporary files, then after some time all the data will be sent to the client and the buffer will become empty.

In total: the smart buffering algorithm is designed to smooth out the problem of data accumulation in memory in case of peak loads

#### The Task:

You need to use the proposed blank classes and tests.

The first step is to complete the Swap::Buffer class. Comments in the class implementation list what needs to be done. After the work on Swap::Buffer is completed, the test "one" should start to work

The second step is to implement the "two" and "three" tests. what exactly they should do is indicated in the comments.

Estimated development time: 1-2 days. If there is not enough time, step 3 is not necessary

Step 3: Implement the File and Chunk classes. set MAX_BUFFER_SIZE to 1M. Switch to using File in Item::Append if an overflow occurs. the "two" and "three" tests should still work

Estimated development time: 1 (maximum 2 days)


### ATTENTION !!!
the code must be formatted in accordance with the requirements described in doc/CodingStyle.pdf
Please pay attention to how the code that already exists is written. Try to write in the same style