Name:		capi-system-info
Summary:	A System Information library in Core API
Version:	0.2.0
Release:	0
Group:		System/Libraries
License:	Apache-2.0
Source0:	%{name}-%{version}.tar.gz
Source1001:	%{name}.manifest
Source2001:	tizenid.service
BuildRequires:	cmake
BuildRequires:	pkgconfig(dlog)
BuildRequires:	pkgconfig(capi-base-common)
BuildRequires:	pkgconfig(iniparser)
BuildRequires:	pkgconfig(libxml-2.0)
BuildRequires:	pkgconfig(openssl)
BuildRequires:	pkgconfig(glib-2.0)

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

%define config_file_path /etc/config/model-config.xml
%define info_file_path /etc/info.ini
%define os_release_file_path /etc/os-release
%define serial_path /csa/imei/serialno.dat

# tizenid.service should be changed if the path is changed
%define tizen_id_path /etc/tizenid

%if "%{?tizen_profile_name}" == "tv"
%define product_plugin ON
%else
%define product_plugin OFF
%endif

%build
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
cmake . -DCMAKE_INSTALL_PREFIX=/usr \
		-DFULLVER=%{version} -DMAJORVER=${MAJORVER} \
		-DCONFIG_FILE_PATH=%{config_file_path} \
		-DINFO_FILE_PATH=%{info_file_path} \
		-DOS_RELEASE_FILE_PATH=%{os_release_file_path} \
		-DSERIAL_PATH=%{serial_path} \
		-DTIZEN_ID_PATH=%{tizen_id_path} \
		-DPRODUCT_PLUGIN=%{product_plugin}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}

%make_install
mkdir -p %{buildroot}/usr/share/license
cp -f LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}

mkdir -p %{buildroot}/etc
cp -f script/make_info_file.sh %{buildroot}/etc/make_info_file.sh

mkdir -p %{buildroot}%{_libdir}/systemd/system/multi-user.target.wants
install -m 0644 %SOURCE2001 %{buildroot}%{_libdir}/systemd/system/tizenid.service
ln -s ../tizenid.service %{buildroot}%{_libdir}/systemd/system/multi-user.target.wants/tizenid.service

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%manifest %{name}.manifest
/usr/share/license/%{name}
%{_libdir}/libcapi-system-info.so.*
%attr(0744,root,-) /etc/make_info_file.sh

#tizenid
%{_bindir}/tizen_id
%{_libdir}/systemd/system/tizenid.service
%{_libdir}/systemd/system/multi-user.target.wants/tizenid.service

#product plugin
%if %{?product_plugin} == ON
%{_libdir}/libsystem-info-external-plugin.so
%endif

%files devel
%manifest %{name}.manifest
%{_includedir}/system/system_info.h
%{_includedir}/system/system_info_type.h
%{_includedir}/plugin/system_info_intf.h
%{_libdir}/pkgconfig/*.pc
%{_libdir}/libcapi-system-info.so
