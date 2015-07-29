#ifndef GUARD_pic_h
#define GUARD_pic_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Ptr.h"

using std::max;

// �ӿ��࣬������ǰ����������ΪPic_base���ж�operator<<��������Ԫ�������õ���const Picture&������
class Picture;

// ����
class Pic_base {
	// Ϊɶ��Ԫ���������������ἤ��height()������display()���������Ҫ�����������Է�����Щ����
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	// ������Ϊɶ��Ԫ������
	// ������ֻ�ܷ�����Ķ�������ӵ�еı�����Ա����������û�з�����������ı�����Ա����Ȩ P298
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;

public:
	virtual ~Pic_base() { }

protected:
	// ����ϣ�����Դ��κ�һ���������з��������������˽��˺�������ΪPic_base���һ����Ա����
	// ���ҽ��䶨��Ϊ��̬�ģ�static���ͱ������͵ģ�protected��
	static void pad(std::ostream& os, wd_sz, wd_sz);
};

// �ӿ���
class Picture {
	// ������Щ���������õ�Picture���Ͷ������Ptr���Ͷ�����˱����÷���Ptr���Ա��Ȩ��
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);

public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());

private:
	Picture(Pic_base* ptr) : p(ptr) { } 
	// ��ÿ������ͨ��Ptr���Ͷ���ת���ײ�������������ʵ�ָò���
	Ptr<Pic_base> p;
};

// ����������Щ��������ı��������õ�Picture���Ͷ����״̬�����û�б�Ҫ�����Ƕ���ΪPicture�ĳ�Ա����
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


class String_Pic : public Pic_base 
{
	// ��Picture�ඨ���String_Pic���һ����Ԫ�࣬�����Ϳ���ͨ��Picture�����String_Pic��Ĺ��캯��
	friend class Picture;
	std::vector<std::string> data;
	// �����������v�н��ײ���ַ������Ƶ��������ݳ�Ա���������������Ψһ���ַ����и��Ƶĵط���
	// �������ط�������ֻ�Ǹ���Ptr<Pic_base>������ʵ����ֻ�Ǹ�����ָ�룬ʹ���ü���������һ��
	String_Pic(const std::vector<std::string>& v) : data(v) { }

	ht_sz height() const { return data.size(); }
	wd_sz width() const;
	void display(std::ostream&, ht_sz, bool) const;
};


class VCat_Pic : public Pic_base
{
	friend Picture vcat(const Picture&, const Picture&);
	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) :
		top(t), bottom(b) { }

	wd_sz width() const
	{
		return max(top->width(), bottom->width());
	}

	ht_sz height() const
	{
		return top->height() + bottom->height();
	}

	void display(std::ostream&, ht_sz, bool) const;
};


class HCat_Pic : public Pic_base
{
	friend Picture hcat(const Picture&, const Picture&);
	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) :
		left(l), right(r) { }

	wd_sz width() const { return left->width() + right->height(); }
	ht_sz height() const { return max(left->height(), right->height()); }

	void display(std::ostream&, ht_sz, bool) const;
};


class Frame_Pic : public Pic_base
{
	// ���ﶨ��Ϊ��Ԫ��������Ϊframe������Ҫ����Frame_Pic���͵Ķ��󣬶�Frame_Pic��Ĺ��캯����˽�е�
	friend Picture frame(const Picture&);
	Ptr<Pic_base> p;
	// ֻ��Ҫ�ѽ�Ҫ�����Ͽ�ܵ�Դ�����Ƶ�Ptr���Ͷ����м���
	Frame_Pic(const Ptr<Pic_base> pic) : p(pic) { }

	wd_sz width() const { return p->width() + 4; }
	ht_sz height() const { return p->height() + 4; }
	void display(std::ostream&, ht_sz, bool) const;
};


#endif