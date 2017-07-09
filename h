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
        i)
            shift
            composer install
            if [[ ! -f .env ]]; then
                cp -vf .env.example .env
            fi
            php artisan key:generate
            ;;
        a)
            shift
            php artisan $@
            shift $#
            ;;
        ag)
            shift
            php artisan migrate
            shift $#
            ;;
        am)
            shift
            model=App\\Models\\$1
            shift
            php artisan make:model $model $@
            shift $#
            ;;
        s)
            shift
            php artisan serve
            ;;
        hg)
            shift
            php artisan ide-helper:generate
            ;;
        ht)
            shift
            php artisan ide-helper:meta
            ;;
        hm)
            shift
            model=
            for i in "$@"
            do
                model="$model App\\Models\\$i"
            done
            php artisan ide-helper:models -W -R $model
            shift $#
            ;;
        *)
            shift
            echo $key "doesn't exist!"
            exit -1
            ;;
    esac
done
