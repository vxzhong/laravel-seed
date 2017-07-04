#! /usr/bin/env bash

if [[ $# -eq 0 ]]; then
    php artisan ide-helper:generate
    php artisan ide-helper:meta
    exit 0
fi

while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        -g)
            shift
            php artisan ide-helper:generate
        ;;
        -m)
            shift
            php artisan ide-helper:meta
        ;;
        -mwr)
            shift
            model=
            for i in "$@"
            do
                model="$model App\\Models\\$i"
            done
            php artisan ide-helper:models -W -R $model
            shift $#
        ;;
        -s)
            shift
            php artisan serve
        ;;
    esac
done