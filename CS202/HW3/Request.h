/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Request class header file for CS202's HW3 assignment.
 */

#ifndef __REQUEST_H__
#define __REQUEST_H__

typedef int RequestItemType;

class Request {
public:
    Request();
    Request(RequestItemType id, RequestItemType priority, RequestItemType requestTime,
            RequestItemType processTime, bool isQueued);
    Request(const Request& otherRequest);
    Request& operator=(const Request& otherRequest);
    ~Request();

    void setId(const RequestItemType& id);
    void setPriority(const RequestItemType& priority);
    void setRequestTime(const RequestItemType& requestTime);
    void setProcessTime(const RequestItemType& processTime);
    void setIsQueued(const bool& isQueued);

    RequestItemType getId() const;
    RequestItemType getPriority() const;
    RequestItemType getRequestTime() const;
    RequestItemType getProcessTime() const;
    bool getIsQueued() const;

    friend bool operator>(const Request& r1, const Request& r2);

private:
    RequestItemType id;
    RequestItemType priority;
    RequestItemType requestTime;
    RequestItemType processTime;
    bool isQueued;
};

#endif // __REQUEST_H__
