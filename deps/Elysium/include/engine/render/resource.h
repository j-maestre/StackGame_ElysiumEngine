#ifndef __RESOURCE_H__
#define __RESOURCE_H__ 1

/**
 * @class Resource
 * @brief Base class for resources in the application.
 */
class Resource {
public:

    /**
     * @brief Virtual function for binding the resource.
     * @details Derived classes should override this function to provide specific binding behavior.
     */
	virtual void bind() {};
};

#endif
