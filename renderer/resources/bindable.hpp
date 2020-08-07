#ifndef BINDABLE_HPP
#define BINDABLE_HPP

class IBindable {
public:
	virtual ~IBindable() = default;
	virtual void bind() = 0;
};

#endif