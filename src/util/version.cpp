#include "util/version.h"

#include "defs_version.h"
#include "build.h" // Generated by SCons

// static
QString Version::version() {
    return VERSION;
}

// static
QString Version::applicationTitle() {
#ifdef __APPLE__
    QString base("Mixxx");
#elif defined(AMD64) || defined(EM64T) || defined(x86_64)
    QString base("Mixxx " VERSION " x64");
#elif defined(IA64)
    QString base("Mixxx " VERSION " Itanium");
#else
    QString base("Mixxx " VERSION);
#endif

#ifdef MIXXX_BUILD_NUMBER_IN_TITLE_BAR
    QString branch = developmentBranch();
    QString branch_revision = developmentRevision();
    if (!branch.isEmpty() && !branch_revision.isEmpty()) {
        base.append(QString(" (build %1-r%2)")
                    .arg(branch).arg(branch_revision));
    }
#endif
    return base;
}

// static
QString Version::developmentBranch() {
#ifdef BUILD_BRANCH
    return BUILD_BRANCH;
#else
    return QString();
#endif
}

// static
QString Version::developmentRevision() {
#ifdef BUILD_REV
    return BUILD_REV;
#else
    return QString();
#endif
}

// static
QString Version::buildFlags() {
#ifdef BUILD_FLAGS
    return BUILD_FLAGS;
#else
    return QString();
#endif
}
