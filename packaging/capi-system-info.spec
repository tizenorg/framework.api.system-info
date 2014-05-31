Name:		capi-system-info
Summary:	A System Information library in Core API
Version:	0.2.0
Release:	0
Group:		System/Libraries
License:	Apache License, Version 2.0
Source0:	%{name}-%{version}.tar.gz
Source1001: 	%{name}.manifest
BuildRequires:	cmake
BuildRequires:	pkgconfig(dlog)
BuildRequires:	pkgconfig(capi-base-common)
BuildRequires:	pkgconfig(iniparser)
BuildRequires: 	pkgconfig(libxml-2.0)

Requires(post):	/sbin/ldconfig
Requires(postun): /sbin/ldconfig

%description


%package devel
Summary:  A System Information library in Core API (Development)
Group:    Development/System
Requires: %{name} = %{version}-%{release}

%description devel


%prep
%setup -q
cp %{SOURCE1001} .

%build
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DFULLVER=%{version} -DMAJORVER=${MAJORVER}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}

%make_install
mkdir -p %{buildroot}/usr/share/license
cp -f LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}

mkdir -p %{buildroot}/etc
cp -f script/make_info_file.sh %{buildroot}/etc/make_info_file.sh

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%manifest %{name}.manifest
/usr/share/license/%{name}
%{_libdir}/libcapi-system-info.so.*
%attr(0744,root,-) /etc/make_info_file.sh

%files devel
%manifest %{name}.manifest
%{_includedir}/system/system_info.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/libcapi-system-info.so
